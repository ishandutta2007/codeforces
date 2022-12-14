#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const int Alpha=28;
const int MAXLEN=1000005;
long long dp[MAXLEN*2];
int vis[MAXLEN*2];
int Q=0;
class SuffixAutomata{
    public:
    struct state {
        int len, link;
        int next[Alpha];
        state(){
            len = link = 0;
            memset(next , -1 , sizeof(next));
        }
    };
    int sz=1, last=0;
    vector<state> st;
    vector<int> terminal;
    void Init(int len) {
        st.clear();
        terminal.clear();
        st.resize(2*len);
        terminal.resize(2*len);
        sz = 1;
        last=0;
        st[0].len = 0;
        st[0].link = -1;

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
    void build(string s)
    {
        for (auto x:s)extend(x);
        getTerminal();
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
    void solve(string t)
    {
        Q++;
        int L = t.size();
        t=t+t,t.pop_back();
        long long ret=0;
        int v=0;
        int j=0;
        for(int i=0;i<t.size();i++)
        {
            if (j<i)j=i,v=0;
            while(j-i<L && j<t.size())
            {
                if (st[v].next[t[j]-'a']==-1)break;
                v=st[v].next[t[j]-'a'];
                j++;
            }
            if (j-i==L && vis[v]!=Q)ret+=DP(v),vis[v]=Q;
            int curLen = j-i;
            if (curLen-1 < st[st[v].link].len+1)
                v = st[v].link;
        }
        cout<<ret<<endl;
    }
}SA;
int main()
{
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    SA.Init(s.size());
    SA.build(s);
    int n;
    cin>>n;
    while(n--)
    {
        string t;
        cin>>t;
        SA.solve(t);
    }
}