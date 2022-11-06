#include<bits/stdc++.h> 
#define ll long long  
using namespace std;  
  
const int mod=1e9+7;  
int a[510];  
ll A[510],C[510][510],dp[510][510],b[510];
bool v[510];

void init(){  
    A[1]=1;  
    for(int i=2;i<510;i++)  
        A[i]=(i*A[i-1])%mod;  
    for(int i=0;i<510;i++){  
        C[i][0]=C[i][i]=1;  
        for(int j=1;j<i;j++)  
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;  
    }  
}  

bool sq(ll x)
{
	ll tmp=sqrt(x);
	if (tmp*tmp==x) return true; else return false;
}

int main()  
{  
  
    init();  
    int t,n,m,cas=1;  
    scanf("%d",&m);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	memset(v,true,sizeof(v));n=0;
	for (int i=1;i<=m;i++)
	{
	    if (v[i]){
		    n++;v[i]=false;
            a[n]=1;
            for (int j=i+1;j<=m;j++) if (sq(b[i]*b[j])){
            	v[j]=false;
            	a[n]++;
            }
        }
    } 
    memset(dp,0,sizeof dp);  
    dp[1][a[1]-1]=1;  
    int sum=a[1];  
    for(int i=2;i<=n;i++){  
        for(int j=0;j<sum;j++){  
            if(!dp[i-1][j]) continue;  
            for(int k=1;k<=a[i];k++)  
                for(int z=0;z<=j&&z<=k;z++){  
                    if(k-z>sum+1-j) continue;  
                        int h=j+a[i]-k-z;  
                        dp[i][h]=(dp[i][h]+dp[i-1][j]*C[a[i]-1][k-1]%mod*C[sum+1-j][k-z]%mod*C[j][z]%mod)%mod;  
                    }  
            }  
            sum+=a[i];  
        }  
    for(int i=1;i<=n;i++)  
        dp[n][0]=(dp[n][0]*A[a[i]])%mod;  
    printf("%d\n",dp[n][0]);
    return 0;  
}