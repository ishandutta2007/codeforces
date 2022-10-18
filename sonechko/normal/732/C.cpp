#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 3000+10;
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
ll a[10];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    #endif // LOCAL
    cin>>a[1]>>a[2]>>a[3];
    ll ans=LONG_LONG_MAX;
    for (int i=1; i<=4; i++)
        for (int j=1; j<=4; j++)
    {
        ll l1=0,r1=0,k1=0;
        if (i<=1) l1++;
        if (i<=2) r1++;
        if (i<=3) k1++;
        if (j>=1) l1++;
        if (j>=2) r1++;
        if (j>=3) k1++;
        a[1]-=l1;
        a[2]-=r1;
        a[3]-=k1;
        ll d=0;
        d+=max(a[1],max(a[2],a[3]))-a[1];
        d+=max(a[1],max(a[2],a[3]))-a[2];
        d+=max(a[1],max(a[2],a[3]))-a[3];
        a[1]+=l1;
        a[2]+=r1;
        a[3]+=k1;
        ans=min(ans,d);
    }
    if (a[1]==0&&a[2]==0&&a[3]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if (a[1]<=1&&a[2]<=1&&a[3]<=1) cout<<0<<endl;
    else cout<<ans<<endl;
}