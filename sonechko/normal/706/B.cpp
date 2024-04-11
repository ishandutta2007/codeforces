#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000+10;
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
#define se second
#define ll long long
#define fi first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
int a[100001];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int k;
        cin>>k;
        int l=0,r=n;
        while (l+1<r)
        {
            int h=(l+r)/2;
            if (a[h]<=k) l=h; else r=h;
        }
        if (a[r]<=k) cout<<r<<endl; else cout<<l<<endl;
    }
}