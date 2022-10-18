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

int main()
{
    int l,r,k;
    cin>>l>>r>>k;
    for (int i=0; i<=l; i++)
    {
        if (i>r) break;
        int p = l-i;
        int g = r-i;
        int t = k;

        if (k==(p+g)) {cout<<i<<" "<<g<<" "<<p; return 0;}
    }
    cout<<"Impossible"<<endl;
}