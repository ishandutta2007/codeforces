#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000+5;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
vector<int> vt[N];
int hg[N],g;
int use[N],p[N];
void dfs(int v)
{
    use[v]=2;
    for (int i=0; i<vt[v].size(); i++)
    if (use[vt[v][i]]!=2) dfs(vt[v][i]);
}
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
    sync;
#endif

int n;
cin>>n;
for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l==i) {} else
        vt[l].push_back(i);
        p[i]=l;
    }
int ch=0,ans=0,t=0;
for (int i=1; i<=n; i++)
{
    if (vt[i].size()==0&&use[i]==0)
    {

        int k=i,t=0;
        use[k]=1;
        while (p[k]!=k)
            {
                use[k]=1;
                if (use[p[k]]==1) {g++; hg[g]=k; t=1; break;}
                k=p[k];
                use[k]=1;
            }
        dfs(k);
        if (t==0)
        {
        if (ch==0) {ch=k;} else {ans++; p[k]=ch;}
        }
    }
}
for (int i=1; i<=n; i++)
{
    if (use[i]==0)
    {
        //cout<<i<<endl;
        if (ch==0) { ch=i; ans++; p[i]=i;} else {ans++; p[i]=ch;}
        dfs(i);
    }
}
for (int i=1; i<=g; i++)
{
    if (ch==0) {ch=hg[i]; ans++; p[hg[i]]=hg[i];} else {ans++; p[hg[i]]=ch;}
}
cout<<ans<<endl;
for (int i=1; i<=n; i++)
    cout<<p[i]<<" ";
cout<<endl;
}