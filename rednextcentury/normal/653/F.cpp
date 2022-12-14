#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = (500105);
const int Alpha = 2;
int n;
string s;
long long ans=0;
struct state {
    int len, link;
    int next[Alpha];
    state(){
        len = link = 0;
        memset(next , -1 , sizeof(next));
    }
    void reset()
    {
        len = link = 0;
        memset(next , -1 , sizeof(next));
    }
};
state st[MAXLEN*2];
vector<int> loc[MAXLEN*2];
int sum[MAXLEN*2];
int L[MAXLEN*2];
bool vis[MAXLEN*2];
int Cnt(int x,int l,int r)
{
    if (l>r)return 0;
    return upper_bound(loc[x].begin(),loc[x].end(),r)-lower_bound(loc[x].begin(),loc[x].end(),l);
}
int Query(int l,int r)
{
    l=max(l,L[r+1]+1);
    return Cnt(sum[r+1],l,r);
}
class SuffixAutomata{
    public:
    int sz, last;
    void init() {
        for(int j = 0 ; j < 2*MAXLEN ; j++) st[j] = state();
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
    }
    void extend(char ccc) {
        int c=1;
        if (ccc=='(')c=0;
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
    void solve()
    {
        int cur=0;
        for (int i=0;i<s.size();i++)
        {
            int val=1;
            if (s[i]=='(')val=0;
            cur=st[cur].next[val];
            int v = cur;
            while(v!=0)
            {
                int l = i-st[v].len+1;
                int r = i-st[st[v].link].len+1;
                if (!vis[v]){
                    ans+=Query(l,i)-Query(r,i);
                    vis[v]=1;
                    v=st[v].link;
                } else {
                    break;
                }
            }
        }
    }
}SA;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    sum[n]=n;
    for (int i=n-1;i>=0;i--)
    {
        sum[i]=sum[i+1];
        if (s[i]==')')sum[i]++;
        else sum[i]--;
    }
    for (int i=0;i<n;i++)
        loc[sum[i]].push_back(i);
    stack<int> st;
    for (int i=0;i<=n;i++)
    {
        while(!st.empty() && sum[st.top()]>=sum[i])
            st.pop();
        if (st.empty())L[i]=-1;
        else L[i]=st.top();
        st.push(i);
    }
    SA.init();
    for (auto x:s)SA.extend(x);
    SA.solve();
    cout<<ans<<endl;
}