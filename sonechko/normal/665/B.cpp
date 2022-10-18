#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000000;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
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
int a[102],b[102];
int main()
{

    int hj1,hj2,n;
    cin>>hj1>>hj2>>n;
    int m=hj1*hj2;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[a[i]]=i;
        }
    int ans=0;
    for (int j=1; j<=m; j++)
    {
        int l;
        cin>>l;
        int k=b[l];
        ans+=k;
        for (int i=1; i<=n; i++)
            if (i==l) b[i]=1; else
            if (b[i]<k) b[i]++;
    }
    cout<<ans<<endl;
}