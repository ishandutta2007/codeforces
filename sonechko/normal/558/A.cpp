#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 104;
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
int n;
pair<int,int> a[N];
int b[N],c[N];
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].f>>a[i].s;
    sort(a+1,a+n+1);
    int k1=0,k2=0;
    for (int i=1; i<=n; i++)
        if (a[i].f<0) k1++;
    k2=k1;
    for (int i=1; i<=n; i++)
        if (a[i].f<0)
        {
            b[k2]=a[i].s;
            k2--;
        }
    k2=0;
    int ans=0;
    for (int i=1; i<=n; i++)
        if (a[i].f==0) ans+=a[i].s; else
    if (a[i].f>0) {k2++; c[k2]=a[i].s;}
    int l=0,r=0,k=0,ans1=ans;
    while (1==1)
    {
        if (k==0)
        {
            if (l==k1) break;
            l++;
            ans1+=b[l];
        } else
        {
            if (r==k2) break;
            r++;
            ans1+=c[r];
        }
        k=1-k;
    }
    l=0;
    r=0;
    k=1;
    int ans2=ans;
    while (1==1)
    {
        if (k==0)
        {
            if (l==k1) break;
            l++;
            ans2+=b[l];
        } else
        {
            if (r==k2) break;
            r++;
            ans2+=c[r];
        }
        k=1-k;
    }
    cout<<max(ans1,ans2)<<endl;
}