#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = (400005);
const int Alpha = 28;
long long MOD = 1e9 + 7;
long long dp[MAXLEN*2][3];
long long ans[MAXLEN*2];
int minLen;
int longest[MAXLEN*2];
struct state {
    int len, link;
    int next[Alpha];
    vector<pair<int,int> > pre;
    state(){
        len = link = 0;
        memset(next , -1 , sizeof(next));
        pre.clear();
    }
};
state st[MAXLEN*2];
long long num[MAXLEN*2];
int terminal[MAXLEN*2];
class SuffixAutomata{
    public:
    int sz, last;
    void init() {
        for(int j = 1 ; j < MAXLEN ; j++) st[j] = state();
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
    int getLongest(int v)
    {
        if (longest[v]!=-1e8)return longest[v];
        if (v==0)return 0;
        int ret=-1e7;
        for (auto u:st[v].pre)
        {
            if (u.second==27)continue;
            ret=max(ret,getLongest(u.first)+1);
        }
        return longest[v]=ret;
    }
    void getReversed()
    {
        for (int i=0;i<sz;i++)
        {
            for (int j=0;j<Alpha;j++)
            {
                if (st[i].next[j]!=-1)
                    st[st[i].next[j]].pre.push_back({i,j});
            }
        }
        for (int i=0;i<sz;i++)
            longest[i]=-1e8;
        for (int i=0;i<sz;i++)
            getLongest(i);
    }
    long long DP(int i,int j)
    {
        if (j<0)return 0;
        if (dp[i][j]!=-1)
            return dp[i][j];
        long long ret=(terminal[i] && j==0);
        for (int x=0;x<Alpha;x++)
        {
            ret+=DP(st[i].next[x],j-(x==27));
        }
        return dp[i][j]=ret;
    }
    void solve()
    {
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<sz;i++)
            for (int j=0;j<3;j++)
                DP(i,j);
        long long mod=1000000007;
        for (int i=0;i<sz;i++)
        {
            long long cur=1;
            for (int j=0;j<3;j++)
                cur=(cur*dp[i][j])%mod;
            int l = st[st[i].link].len+1;
            int r = longest[i];
            if (l<=r)
                ans[l]+=cur,ans[l]%=mod,ans[r+1]+=mod-cur,ans[r+1]%=mod;
        }
        for (int i=1;i<=minLen;i++)
        {
            ans[i]=(ans[i]+ans[i-1])%mod;
            cout<<ans[i]<<' ';
        }
        cout<<endl;
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
    string a,b,c;
    cin>>a>>b>>c;
    string s = a+"|"+b+"|"+c;
    minLen = min(a.size(),min(b.size(),c.size()));
    SA.init();
    for (auto x:s)SA.extend(x);
    SA.getTerminal();
    SA.getReversed();
    SA.solve();
}