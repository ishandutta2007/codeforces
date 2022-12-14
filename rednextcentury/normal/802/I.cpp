#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = (500005);
const int Alpha = 28;
long long MOD = 1e9 + 7;
long long dp[MAXLEN*2];
struct state {
    int len, link;
    int next[Alpha];
    state(){
        len = link = 0;
        memset(next , -1 , sizeof(next));
    }
};
state st[MAXLEN*2];
int terminal[MAXLEN*2];
class SuffixAutomata{
    public:
    int sz, last;
    void init() {
        for(int j = 0 ; j < MAXLEN ; j++) st[j] = state() , dp[j]=-1, terminal[j]=0;
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
    }
    void extend(char ccc) {
        int c = ccc - 'a';
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        }
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                for(int j = 0 ; j < Alpha ; j++)
                    st[clone].next[j] = st[q].next[j];
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void getTerminal()
    {
        int p=last;
        while(p>0)terminal[p]=1,p=st[p].link;
    }
    long long DP(int i)
    {
        if (dp[i]!=-1)
            return dp[i];
        long long ret=(terminal[i]);
        for (int x=0;x<Alpha;x++)
        {
            if (st[i].next[x]!=-1)
                ret+=DP(st[i].next[x]);
        }
        return dp[i]=ret;
    }
    long long solve()
    {
        long long mod = 1000000007;
        long long ret=0;
        for (int i=1;i<sz;i++)
        {
            long long x = DP(i);
            x=x*x;
            x*=st[i].len - st[st[i].link].len;
            ret+=x;
        }
        cout<<ret<<endl;
    }
    void print()
    {
        cout<<"Number of States: "<<sz<<endl;
        cout<<"Terminal States: ";
        for (int i=0;i<sz;i++)if (terminal[i])cout<<i<<" ";
        cout<<endl;
        cout<<"Edges:"<<endl;
        for (int i=0;i<sz;i++)
        {
            for (int j=0;j<Alpha;j++)
            {
                if (st[i].next[j]!=-1)
                    cout<<i<<' '<<st[i].next[j]<<' '<<char('a'+j)<<endl;
            }
        }
    }
}SA;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        string t;
        cin>>t;
        SA.init();
        for (auto x:t)SA.extend(x);
        SA.getTerminal();
        SA.solve();
    }
}