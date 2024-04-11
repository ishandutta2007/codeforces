#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100004;
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
int n,a[N],b[N];
int main()
{
    sync;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
    sort(b+1, b+n+1);
    int k=0;
    for (int i=1; i<=n; i++)
    if (a[i]!=b[i]) {k=1; break;}
    if (k==0) {cout<<"yes"<<endl; cout<<"1 1"<<endl; return 0;}
    int l=1;
    int r=n;
    while(a[l]==b[l])
        {
            l++;
        }
    while(a[r]==b[r])
    {
        r--;
    }
    k=l;
    for (int i=r; i>=l; i--)
    {
        if (a[i]!=b[k]) {cout<<"no"<<endl; return 0;}
        k++;
    }
    cout<<"yes"<<endl;
    cout<<l<<" "<<r<<endl;
}