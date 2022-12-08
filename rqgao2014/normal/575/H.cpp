#include<cstdio>
#include<iostream>
using namespace std;

int n; 
int fac[2000010],a[2000010];
const int mod=1000000007;
int ans=0;

int fpow(int i,int j)
{int ret;

 if(j==0)
 	return 1;
 ret=fpow(i,j/2);
 ret=(long long)ret*ret%mod;
 if(j%2==1)
 	ret=(long long)ret*i%mod;
 return ret;
}

int inv(int i)
{if(a[i]!=0)
 	return a[i];
 else
 {	a[i]=fpow(fac[i],mod-2);
 	return a[i];
 }
}

int calc(int i,int j)
{int ret;
 ret=(long long)fac[i]*inv(j)%mod*inv(i-j)%mod;
 return ret;
}

int main()
{int i,j,s=0;
 
 fac[0]=1;
 for(i=1;i<=2000000;i++)
 	fac[i]=(long long)fac[i-1]*i%mod;	
 
 scanf("%d",&n);
 
 ans=((long long)fpow(2,n+1)-1+mod)%mod;
 ans%=mod;
 s=fpow(2,n);
 a[n]=fpow(fac[n],mod-2);
 for(i=n+1;i<=2*n;i++)
 {	s=((long long)s*2-calc(i-1,n)-calc(i-1,i-1-n))%mod;
 	ans=((long long)ans+s+mod)%mod;
 	//cout<<i<<" "<<s<<endl;
 }
 
 cout<<ans<<endl;
 
 return 0;
}