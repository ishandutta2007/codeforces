#include<bits/stdc++.h>

const long long MOD = 1e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define ll unsigned long long
#define endl "\n"

using namespace std;

int main()
{
    string s;
    cin>>s;
    if (s[s.size()-1]=='C') s=s+"P"; else s=s+"C";
    int ans=0;
    int l=0;
    for (int i=0; i<s.size(); i++)
    {
        if (i==0) l=1; else
        if (s[i]==s[i-1]) l++; else
        {
            ans+=(l+4)/5;
            l=1;
        }
    }
    cout<<ans<<endl;
}