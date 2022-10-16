#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
const int mod=1e9+7;
int cha[N][N]; 
int ans[N];
int martix[N];
int n,b,k,x;
void mul()
{

	memset(martix,0,sizeof(martix));
	for(int i=0;i<x;i++)
		for(int j=0;j<x;j++)
			martix[i]=(martix[i]+ans[j]*cha[j][i])%mod;
	memcpy(ans,martix,sizeof(ans));
}
void mulself()
{
	int martix[N][N];
	memset(martix,0,sizeof(martix));
	for(int i=0;i<x;i++)
		for(int j=0;j<x;j++)
			for(int k=0;k<x;k++)
				martix[i][j]=(martix[i][j]+cha[i][k]*cha[k][j])%mod;
	memcpy(cha,martix,sizeof(cha));
}
signed main()
{
    cin>>n>>b>>k>>x;;;;;;
    ans[0]=1;
    for(int i=0;i<n;i++)
    {
        int a;
    	cin>>a;
    	for(int j=0;j<x;j++) cha[j][(10*j+a)%x]++;
	}
	while(b)
	{
		if(b&1) mul();
		mulself();
		b>>=1;
	}
	cout<<ans[k]<<endl;
}