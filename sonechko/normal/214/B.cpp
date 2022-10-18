#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000000;
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
int a[N],b[N],c[N],sz;
string s;
void rec(int k, int t, int ostatok)
{
    if (k==0)
    {

        if (ostatok!=0) return;
        if (t<sz) return;
        if (t>sz) {sz=t; for (int i=0; i<=9; i++) a[i]=c[i]; return;}
        for (int i=9; i>=1; i--)
            if (a[i]>c[i]) return; else
            if (a[i]<c[i]) break;
        for (int i=1; i<=9; i++)
        a[i]=c[i];
        return;
    }
    for (int i=b[k]; i>=max(0,b[k]-2); i--)
    {
        c[k]=i;
        rec(k-1,t+i,(ostatok+i*k)%3);
        c[k]=0;
    }

}
int main()
{
    int n;
    cin>>n;
    int kek=0,lol=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        b[l]++;
        if (l==0) kek=1;
        if (l==0) c[0]++;
        if (l==0) a[0]++;
        if (l!=0) lol=1;
    }
    if (kek==0) {cout<<-1<<endl; return 0;}
    if (lol==0) {cout<<"0"<<endl; return 0;}
    sz=a[0];
    rec(9,a[0],0);
    kek=0;
    for (int i=9; i>=0; i--)
        while (a[i]>0)
    {
        if (i!=0) kek=1;
        if (kek==0&&i==0) {cout<<0<<endl; return 0;}
        cout<<i;
        a[i]--;
    }
}