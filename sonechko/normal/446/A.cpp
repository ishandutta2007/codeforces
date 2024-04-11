#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 100000+10;
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
int a[N],b[N],c[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            if (i==1) b[i]=1; else
            if (a[i]>a[i-1]) b[i]=b[i-1]+1; else
            b[i]=1;
        }
    for (int i=n; i>=1; i--)
    {
        if (i==n) c[i]=1; else
        if (a[i]<a[i+1]) c[i]=c[i+1]+1; else c[i]=1;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        //cout<<b[i-1]<<" "<<c[i+1]<<endl;
        ans=max(ans,b[i-1]+1);
        int k=c[i+1]+1;
        if (a[i+1]-1>a[i-1]) k+=b[i-1];
        ans=max(ans,k);
    }
    cout<<ans<<endl;
}