#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000001;
const int M = 3;
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
vector<int> vec[N],sol[N];
int use[N],use1[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
sync;
    #endif // LOCAL
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int l,r,p;
        cin>>l>>r>>p;
        vec[l].push_back(r);
        sol[l].push_back(p);


        vec[r].push_back(l);
        sol[r].push_back(p);
    }
    for (int i=1; i<=k; i++)
    {
        int x;
        cin>>x;
        use1[x]=1;
    }
    int ans=INT_MAX;
    for (int i=1; i<=n; i++)
        if (use1[i]==0)
    {
        for (int j=0; j<vec[i].size(); j++)
        if (use1[vec[i][j]]==1) {ans=min(ans,sol[i][j]);}
    }
    if (ans==INT_MAX) cout<<"-1"<<endl; else cout<<ans<<endl;
}
/// wGFT4KZJ