#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 100000+10;
const int M = 1000;
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
map<int,int> use;
ll n,m;
int a[N];
void rec(ll l, ll r)
{
    if (l>m) return;
    use[l]=r;
    if (l==m)
    {
        cout<<"YES"<<endl;
        int p=1;
        while (l!=n)
        {
            a[p]=l;
            l=use[l];
            p++;
        }
        cout<<p<<endl;
        cout<<n<<" ";
        for (int i=p-1; i>=1; i--)
            cout<<a[i]<<" ";
        cout<<endl;
        exit(0);
    }
    rec(l*2,l);
    rec(l*10+1,l);
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    #endif // LOCAL
    cin>>n>>m;
    rec(n,0);
    cout<<"NO"<<endl;
}