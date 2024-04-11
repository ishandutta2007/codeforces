#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 300000;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define f first
#define mp make_pair
int a[3][3],b[3][3],ans[4][4][4][4],t;
bool get()
{
    int k=0;
    for (int i=1; i<=2; i++)
    for (int j=1; j<=2; j++)
    if (a[i][j]!=b[i][j]) {k=1; break;}
    if (k==0) return true;
    return false;
}
void rec()
{
    //cout<<"!!"<<endl;
    if (t==1) return;
    if (ans[a[1][1]][a[1][2]][a[2][1]][a[2][2]]!=0) return;
    ans[a[1][1]][a[1][2]][a[2][1]][a[2][2]]=1;
    for (int i=1; i<=2; i++)
        for (int j=1; j<=2; j++)
        if (a[i][j]==0)
    {
        if (i+1<=2) {a[i][j]=a[i+1][j]; a[i+1][j]=0; if (get()){t=1; return;}  rec(); a[i+1][j]=a[i][j]; a[i][j]=0;}
        if (i-1>=1) {a[i][j]=a[i-1][j]; a[i-1][j]=0; if (get()){t=1; return;}  rec(); a[i-1][j]=a[i][j]; a[i][j]=0;}
        if (j+1<=2) {a[i][j]=a[i][j+1]; a[i][j+1]=0; if (get()){t=1; return;}  rec(); a[i][j+1]=a[i][j]; a[i][j]=0;}
        if (j-1>=1) {a[i][j]=a[i][j-1]; a[i][j-1]=0; if (get()){t=1; return;}  rec(); a[i][j-1]=a[i][j]; a[i][j]=0;}
    }
}
int main()
{
    for (int i=1; i<=2; i++)
        for (int j=1; j<=2; j++)
        {
            char ch;
            cin>>ch;
            if (ch=='X') a[i][j]=0; else
            if (ch=='A') a[i][j]=1; else
            if (ch=='B') a[i][j]=2; else a[i][j]=3;
        }
    for (int i=1; i<=2; i++)
        for (int j=1; j<=2; j++)
        {
            char ch;
            cin>>ch;
            if (ch=='X') b[i][j]=0; else
            if (ch=='A') b[i][j]=1; else
            if (ch=='B') b[i][j]=2; else b[i][j]=3;
        }
    rec();
    if (t==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}