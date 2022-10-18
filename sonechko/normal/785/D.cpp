#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD
int a[N],b[N];
long long fact[N];
long long step(int l, int r)
{
    if (r==0) return 1;
    if (r%2==1) return (step(l,r-1)*l)mod;
    long long k=step(l,r/2);
    return (k*k)mod;
}
long long cnk(int l, int r)
{
    if (r==0) return 0;
    long long c1=fact[l];
    c1=(c1*step(fact[r],MOD-2))mod;
    c1=(c1*step(fact[l-r],MOD-2))mod;
    return c1;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin>>s;
    s='.'+s;
    for (int i=1; i<s.size(); i++)
    {
        a[i]=a[i-1];
        if (s[i]=='(') a[i]++;
    }
    for (int i=s.size()-1; i>0; i--)
    {
        b[i]=b[i+1];
        if (s[i]==')') b[i]++;
    }
    fact[0]=1;
    for (int i=1; i<s.size(); i++)
        fact[i]=(fact[i-1]*1LL*i)mod;
    long long ans=0;
    for (int i=1; i<s.size(); i++)
        if (s[i]=='(')
    {
        ans=(ans+cnk(a[i]+b[i]-1,a[i]))mod;
    }
    cout<<ans<<endl;
}