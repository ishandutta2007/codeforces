#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 ll;
const ll mod = 1000000007;
ll A,B,n,x;
ll pow(ll a, ll b)
{
    ll ans = 1;
    ll k = a % mod;
    while(b>0){
        if(b % 2 == 1)//
        ans = (ans * k) % mod;
        b = b/2;
        k = (k * k) % mod;//k
    }
    return ans;
}
ll solve(ll n)
{
    if(n==0) return 1;
    if(n%2==1)
    {
        return (pow(A,n/2+1)+1)*solve(n/2)%mod;
    }else{
        return (A*solve(n-1)+1)%mod;
    }
}
int main()
{
    cin>>A>>B>>n>>x;
    cout<<(pow(A,n)*x%mod+B*solve(n-1)%mod)%mod<<endl;
    return 0;
}