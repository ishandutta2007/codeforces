#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 104;
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
int n;
pair<int,int> a[N];
int b[N],c[N];
int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    if (k>=0)
    {
        if ((m+k)%n==0) cout<<n<<endl; else cout<<(m+k)%n<<endl;
    } else
    {
        k=abs(k);
        while (k>0)
        {
            m--;
            if (m==0) m=n;
            k--;
        }
        cout<<m<<endl;
    }
}