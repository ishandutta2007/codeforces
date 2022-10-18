#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 50000+10;
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
int a[N];
int main()
{
    #ifdef LOCAL
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    cout<<"? "<<n<<" "<<n-1<<endl;
    fflush(stdout);
    int p;
    cin>>p;
    for (int i=2; i<=n; i++)
    {
        cout<<"? "<<1<<" "<<i<<endl;
        cin>>a[i];
    }
    for (int i=1; i<a[n]; i++)
    {
        int k1=a[n]-i;
        int k2=a[n-1]-i;
        if (k1>0&&k2>0&&k1+k2==p) {a[1]=i; break;}
    }
    for (int i=2; i<=n; i++)
        a[i]=a[i]-a[1];
    cout<<"! ";
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
     fflush(stdout);
}