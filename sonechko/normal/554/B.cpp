#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 105;
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
int ans,b[N],n;
string a[N];
void rec(int l,int r)
{
    //cout<<l<<" "<<r<<" "<<endl;
    if (r<=ans) return;
    //for (int i=1; i<=r; i++)
    //    cout<<b[i]<<" ";
    //cout<<endl;
    if (l==n+1) {ans=r; return;}
    int k1=0,k2=0,c[N],d[N];
    for (int i=1; i<=r; i++)
    {
        string s=a[b[i]];
        if (s[l]=='0') {k1++; c[k1]=b[i];} else
            {
                k2++;
                d[k2]=b[i];
            }
    }
    if (k1>k2)
    {
        for (int i=1; i<=k1; i++)
            b[i]=c[i];
        //cout<<"0"<<endl;
        rec(l+1,k1);
        for (int i=1; i<=k2; i++)
            b[i]=d[i];
        //cout<<"1"<<endl;
        rec(l+1,k2);
    } else
    {
        for (int i=1; i<=k2; i++)
            b[i]=d[i];
        //cout<<"1"<<endl;
        rec(l+1,k2);
        for (int i=1; i<=k1; i++)
            b[i]=c[i];
        //cout<<"0"<<endl;
        rec(l+1,k1);
    }
}
int main()
{
    sync;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]='.'+a[i];
        b[i]=i;
    }
    rec(1,n);
    cout<<ans<<endl;
}