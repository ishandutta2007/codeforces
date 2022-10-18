#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 3000000+5;
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
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
int b[1001],c[1001];
char a[1001][1001];
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
    sync;
#endif

int n,m;
int l=0,r=0;
cin>>n>>m;
int ans=0;
int k=0;
for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
{
    char ch;
    cin>>ch;
    if (ch=='*') {b[i]++; c[j]++; k++;}
    a[i][j]=ch;
}
for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        int h=0;
        if (a[i][j]=='*') h--;
        h+=b[i]+c[j];
        if (h==k) {cout<<"YES"<<endl; cout<<i<<" "<<j<<endl; return 0;}
    }
    cout<<"NO"<<endl;
{

}
}