#include<bits/stdc++.h>
#define BetterIO ios::sync_with_stdio(false)
using namespace std;
#define int long long
int A[1000005],B[1000005];
int check(int Val,int N)
{
	for(int i=1;i<=N;i++)B[i]=A[i];
	for(int i=N;i>=3;i--)
	{
		int S=B[i]-Val;
		if(S<0)return 0;
		S=min(S,A[i]);
		int D=S/3;
		B[i]-=D*3;
		B[i-1]+=D;
		B[i-2]+=D*2;
	}
	for(int i=1;i<=N;i++)if(B[i]<Val)return 0;
	return 1;
}
signed main(void)
{
    BetterIO;
   	int Case=1;cin>>Case;while(Case--)
   	{
   		int N;cin>>N;for(int i=1;i<=N;i++)cin>>A[i];
   		int L=1,R=1e9+5,Ans=1;
   		while(L<=R)
   		{
   			int M=L+R>>1;
   			if(check(M,N))Ans=M,L=M+1;
   			else R=M-1;
   		}
   		cout<<Ans<<'\n';
   	}
    return 0;
}