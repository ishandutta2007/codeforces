#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = (600005);
const int Alpha = 28;
long long MOD = 1e9 + 7;
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
int dp[MAXLEN*2][11];
int n;
int L[1000];
int R[1000];
bool vis[1000000];
class SuffixAutomata{
    public:
    int sz, last;
    // Call this function before all tests only!
    void init() {
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
    }
    // Call this function between tests
    void Clear() {
        for(int j = 0 ; j < sz ; j++) {
        	st[j] = state(), terminal[j]=0;
        	// Clear any DP or other additional arrays here
        }
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
    void build(string s)
    {
        for (auto x:s)extend(x);
        getTerminal();
    }
    int DP(int i,int j){
        if (j<0)return 0;
        if (dp[i][j]!=-1)return dp[i][j];
        int ret = (terminal[i] && j==0);
        for (int x=0;x<Alpha;x++)
            if (st[i].next[x]!=-1)
                ret+=DP(st[i].next[x],j-(x==('|'-'a')));
        return dp[i][j]=ret;
    }
    void solve(string s)
    {
        int u=0;
        long long ret=0;
        for (auto x:s)
        {
            if (x=='|')
            {
                u=0;
                continue;
            }
            u = st[u].next[x-'a'];
            int v=u;
            while(1){
                if (vis[v] || v==0)break;
                vis[v]=1;
                long long num = st[v].len - st[st[v].link].len;
                bool ok=1;
                if (DP(v,n)==0)ok=0;
                for (int i=0;i<n;i++)
                {
                    int cur = n-i-1;
                    int D = DP(v,cur);
                    if (D<L[i] || D>R[i])
                        ok=0;
                }
                if (ok)ret+=num;
                v = st[v].link;
            }
        }
        cout<<ret<<endl;
    }
}SA;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    string s;
    cin>>s>>n;
    SA.init();
    for (int i=0;i<n;i++)
    {
        string p;
        cin>>p;
        s+="|";s+=p;
        cin>>L[i]>>R[i];
    }
    SA.build(s);
    SA.solve(s);
}