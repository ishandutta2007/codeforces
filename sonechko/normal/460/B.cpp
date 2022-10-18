#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000005;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define next ljjdfienf
ll a,b,c,t;
int ans,res[N];
int main()
{
    sync;
    cin>>a>>b>>c;
    for (ll i=1; i<=90; i++)
    {
        ll p=i;
        for (int j=1; j<a; j++)
            p*=i;
        p=p*b+c;
        t=p;
        if (p<1000000000&&p>0)
        {
            int k=0;
            while (p>0)
            {
                k+=p%10;
                p/=10;
            }
            if (k==i) {ans++; res[ans]=t;}
        }
    }
    sort(res+1,res+ans+1);
    cout<<ans<<endl;
    for (int i=1; i<=ans; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}