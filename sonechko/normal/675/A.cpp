#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
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
int n,m,k;
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    if (m==0)
    {
        if (k!=n) cout<<"NO"<<endl; else cout<<"YES"<<endl;
    }
    if (m>0)
    {
        if (k<n) cout<<"NO"<<endl; else
        if (n<=0)
        {
            if ((abs(n)+k)%m==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        } else
        if ((k-n)%m==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    if (m<0)
    {
        m=abs(m);
        if (k>n) cout<<"NO"<<endl; else
        if (n<=0||(n>0&&k>0))
        {
            if ((n-k)%m==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        } else
        if ((n+abs(k))%m==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
}