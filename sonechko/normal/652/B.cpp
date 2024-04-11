#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int M = 500001;
const int N = 100006;
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
#define next isehfejrbw

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    int ans[n+1];
    ans[0]=INT_MAX;
    for (int i=1; i<=n; i++)
        if (i%2==1)
    {
        if (a[l]>ans[i-1]) {cout<<"Impossible"<<endl; return 0;}
        ans[i]=a[l]; l++;
    } else
    {
        if (a[r]<ans[i-1]) {cout<<"Impossible"<<endl; return 0;}
        ans[i]=a[r];
        r--;
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}