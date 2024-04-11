#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
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

int main()
{
    int n;
    cin>>n;
    int ans=0;
    int a[500000];
    for (int i=1; i<=1000000; i++)
    {
        int l=i,k=0;
        while(l>0)
        {
            k+=l/5;
            l=l/5;
        }
        //cout<<k<<endl;
        if (k==n) {ans++; a[ans]=i;}
        if (k>n) break;
    }
    cout<<ans<<endl;
    for (int i=1; i<=ans; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}