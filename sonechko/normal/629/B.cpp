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
    int a[n],b[n],c[n];
    for (int i=0; i<n; i++)
    {
        char ch;
        cin>>ch;
        if (ch=='F') c[i]=1; else c[i]=2;
        cin>>a[i]>>b[i];
    }
    int ans=0;
    for (int j=1; j<=366; j++)
    {
        int k1=0, k2=0;
        for (int i=0; i<n; i++)
        if (a[i]<=j&&j<=b[i])
            {if (c[i]==1) k1++;
        else k2++;}
        ans=max(ans,min(k1,k2));
    }
    cout<<ans*2<<endl;
}