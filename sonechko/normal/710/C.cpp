#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 50;
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
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe

//#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))

#define next ifhiuebf
#define last dkbffjrb
int a[N][N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    int l=1, r=2, k=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        if (abs(n/2+1-j)<=k) {cout<<l<<" "; l+=2;} else {cout<<r<<" "; r+=2;}
        cout<<endl;
        if (i<=n/2) k++; else k--;
    }
}