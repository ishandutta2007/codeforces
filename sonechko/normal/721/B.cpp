#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100+10;
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
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
pair<int,pair<int,string> > a[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        a[i]=mp((int)s.size(),mp(1,s));
    }
    string p;
    cin>>p;
    for (int i=1; i<=n; i++)
    if (a[i].s.s==p) a[i].s.f=0;
    sort(a+1,a+n+1);
    int ans=0,l=0;
    for (int i=1; i<=n; i++)
    {
        if (l==m) {l=0;ans+=5;}
        ans++;
        l++;
        if (a[i].s.s==p) break;
    }
    int ans1=ans;
    ans=0;
    for (int i=1; i<=n; i++)
    a[i].s.f=1-a[i].s.f;
    sort(a+1,a+n+1);
    l=0;
    for (int i=1; i<=n; i++)
    {
        if (l==m) {l=0;ans+=5;}
        ans++;
        l++;
        if (a[i].s.s==p) break;
    }
    cout<<ans1<<" "<<ans<<endl;
}