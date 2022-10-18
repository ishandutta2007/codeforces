#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000005;
const int M = 10;
const string charA = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string chara = ".abcdefghijklmnopqrstuvwxyz";
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
int n,m;
int main()
{
    int n;
    cin>>n;
    int l1=INT_MAX,r1=INT_MAX,l2=INT_MIN,r2=INT_MIN;
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        l1=min(l1,x);
        l2=max(l2,x);
        r1=min(r1,y);
        r2=max(r2,y);
    }
    l1=l2-l1;
    r1=max(l1,r2-r1);
    cout<<sqr((long long)r1)<<endl;
}