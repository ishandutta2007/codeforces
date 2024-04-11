#include<bits/stdc++.h>
#define int64 long long
using namespace std;
const int64 mod=1e6+3;
int64 a[410][410];
int n,is[410],js[410];
void exgcd(int a,int b,int &x,int &y){
    if(!b)return x=1,y=0,void();
    exgcd(b,a%b,y,x);y-=x*(a/b);
}
int inv(int p){
    int x,y;exgcd(p,mod,x,y);
    return (x+mod)%mod;
}
void inv(){
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++) 
            for(int j=k;j<=n;j++)if(a[i][j]){
                is[k]=i,js[k]=j;break;
            }
        for(int i=1;i<=n;i++)
            swap(a[k][i],a[is[k]][i]);
        for(int i=1;i<=n;i++)
            swap(a[i][k],a[i][js[k]]);
        if(!a[k][k]){
            puts("No Solution");
            exit(0);
        }
        a[k][k]=inv(a[k][k]); 
        for(int j=1;j<=n;j++)if(j!=k) 
            (a[k][j]*=a[k][k])%=mod;
        for(int i=1;i<=n;i++)if(i!=k) 
            for(int j=1;j<=n;j++)if(j!=k)
                (a[i][j]+=mod-a[i][k]*a[k][j]%mod)%=mod;
        for(int i=1;i<=n;i++)if(i!=k) 
            a[i][k]=(mod-a[i][k]*a[k][k]%mod)%mod;
    }
    for(int k=n;k;k--){ 
        for(int i=1;i<=n;i++)
            swap(a[js[k]][i],a[k][i]);
        for(int i=1;i<=n;i++)
            swap(a[i][is[k]],a[i][k]);
    }
}

int aa[1000];
int f[1000];

int main(){
	n=11;
    for(int i=1;i<=n;i++)
        for(int j=1,tem=1;j<=n;j++)
        {
        	*(a[i]+j)=tem;
        	tem=tem*i%mod;
		}
    inv();
    for (int i=1;i<=n;i++)
    {
    	cout<<'?'<<' '<<i<<endl;
    	fflush(stdout);
    	cin>>f[i];
	}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        	aa[i]=(aa[i]+a[i][j]*f[j])%mod;
    //for (int i=1;i<=n;i++)
    //	cout<<i<<' '<<aa[i]<<endl;
    for (int i=0;i<mod;i++)
    {
    	int ans=0;
    	long long tem=1;
    	for (int j=1;j<=n;j++)
    	{
    		ans=(ans+tem*aa[j])%mod;
    		tem=tem*i%mod;
		}
		//cout<<'#'<<tem<<endl;
		if (ans==0)
		{
			cout<<'!'<<' '<<i<<endl;
			fflush(stdout);
			return 0;
		}
	}
	cout<<'!'<<' '<<-1<<endl;
	fflush(stdout);
    return 0;
}