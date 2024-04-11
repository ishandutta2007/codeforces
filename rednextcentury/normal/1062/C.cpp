#include <bits/stdc++.h>
using namespace std;
int pre[1000000];
long long p[1000000];
int mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s="."+s;
    p[0]=1;
    for (int i=1;i<=n;i++)
        pre[i]=pre[i-1]+(s[i]=='1'),p[i]=(p[i-1]*2)%mod;
    for (int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        int ones = pre[r]-pre[l-1];
        int zero = (r-l+1-ones);
        long long b = (p[ones]-1+mod)%mod;
        long long c = (p[zero]-1+mod)%mod;
        cout<<(b+b*c)%mod<<endl;
    }
}