#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
const int M=605;
const int mod=998244353;

int ans;
int n,m;
bool isprime(int x){for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;return 1;}
int P=0;
int query(int l,int r,int L,int R)
{
    if (P==0) cout<<"? "<<n<<" "<<r-l+1<<" 1 "<<l<<" 1 "<<L<<endl;
    else cout<<"? "<<r-l+1<<" "<<m<<" "<<l<<" 1 "<<L<<" 1"<<endl;
    int x;cin>>x;return x;
}
int chk(int x,int a)
{
    if (x%a!=0) return 1;
    if (a==2)
    {
        int A=query(1,x/2,x/2+1,x);
        if (A==0) return 1;
        return 1+chk(x/2,a);
    } else 
    {
        int t=x/a*(a/2);
        int A=query(1,t,t+1,2*t);if (A==0) return 1;
        int B=query(1,t,t+x/a+1,2*t+x/a+1);if (B==0) return 1;
        return 1+chk(x/a,a);
    }
}
int solve(int x){ans=1;for (int i=2;i<=x;i++) if (x%i==0) if (isprime(i)) ans*=chk(x,i);return ans;}
int main(){cin>>n>>m;int ret=solve(m);P=1;ret*=solve(n);cout<<"! "<<ret<<endl;}
/*

*/