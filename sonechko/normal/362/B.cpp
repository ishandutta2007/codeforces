#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 20001;
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
int a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    sort(a+1,a+m+1);
    for (int i=1; i<=m; i++)
    if (a[i]==n||a[i]==1) {cout<<"NO"<<endl; return 0;}
    for (int i=3; i<=m; i++)
    if (a[i-1]==a[i]-1&&a[i-2]==a[i]-2) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}