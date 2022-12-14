#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = (600005);
const int Alpha = 28;
long long MOD = 1e9 + 7;
long long dp[1000000];
struct state {
    int len, link;
    int next[Alpha];
    state(){
        len = link = 0;
        memset(next , -1 , sizeof(next));
    }
};
state st[MAXLEN * 2];
long long sum[MAXLEN];
long long num[1000000];
int terminal[1000000];
class SuffixAutomata{
    public:
    int sz, last;
    void init() {
        for(int j = 1 ; j < MAXLEN ; j++) st[j] = state();
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
        memset(sum , 0 , sizeof(sum));
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
        if (dp[i]!=-1)return dp[i];
        long long ret=0;
        for (int j=0;j<Alpha;j++)
            if (st[i].next[j]!=-1)
                ret+=DP(st[i].next[j]);
        return dp[i]=ret+terminal[i];
    }
    long long DP2(int i)
    {
        if (num[i]!=-1)return num[i];
        long long ret=0;
        for (int j=0;j<Alpha;j++)
            if (st[i].next[j]!=-1)
                ret+=DP2(st[i].next[j]);
        return num[i]=ret+dp[i];
    }
    string solve(int k)
    {
        getTerminal();
        memset(dp,-1,sizeof(dp));
        memset(num,-1,sizeof(num));
        for (int i=0;i<sz;i++)
            dp[i]=DP(i);
        for (int i=0;i<sz;i++)
            num[i]=DP2(i);
        string ret="";
        int v=0;
        num[0]=0;
        dp[0]=0;
        while(1)
        {
            bool ok=0;
            if (k<=dp[v])return ret;
            else k-=dp[v];
            for (int j=0;j<Alpha;j++)
            {
                int u = st[v].next[j];
                if (u==-1)continue;
                if (num[u]>=k)
                {
                    v = u;
                    ret+=char(j+'a');
                    ok=1;
                    break;
                }
                else
                    k-=num[u];
            }
            if (!ok)
                return ret;
        }
    }


}SA;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int k;
    cin>>k;
    SuffixAutomata SA;
    SA.init();
    for (auto x:s)SA.extend(x);
    string ret=SA.solve(k);
    if (ret.size()==0)ret="No such line.";
    cout<<ret<<endl;
}