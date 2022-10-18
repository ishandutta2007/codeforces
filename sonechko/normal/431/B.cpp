#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed;

int a[5][5];

int f(int l, int r)
{
    return a[l][r]+a[r][l];
}

int get(int a1,int a2,int a3, int a4, int a5)
{
    return f(a1,a2)
    +f(a3,a4)
    +f(a2,a3)
    +f(a4,a5)
    +f(a3,a4)
    +f(a4,a5);
}

int main()
{
    int ans=0;
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
        cin>>a[i][j];
    for (int a1=0; a1<5; a1++)
    for (int a2=0; a2<5; a2++)
    if (a1!=a2)
    for (int a3=0; a3<5; a3++)
    if (a1!=a3&&a2!=a3)
    for (int a4=0; a4<5; a4++)
    if (a1!=a4&&a2!=a4&&a3!=a4)
    for (int a5=0; a5<5; a5++)
    if (a1!=a5&&a2!=a5&&a3!=a5&&a4!=a5)
    ans=max(ans,get(a1,a2,a3,a4,a5));
    cout<<ans<<endl;
}