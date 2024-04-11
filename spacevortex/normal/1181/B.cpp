#include<bits/stdc++.h>
#define cle(x,y) memset(x,0,sizeof(int)*(y))
using namespace std;
const int N=2e5+50;
int n,len;
int w[N],A[N],B[N];
char rs[N];
void put(int *p)
{
	int i;
	//printf("!!!%d\n",p[0]); 
	for(i=p[0];i>=1;i--) printf("%d",p[i]);
	exit(0);
}
int main()
{
//	freopen("t.in","r",stdin);
	int i,x,pd;
	scanf("%d",&n);
	scanf("%s",rs+1);
	for(i=1;i<=n;i++) w[i]=rs[i]-48;
	for(len=n/2;;len--)
	{
		if(w[len+1]==0) A[0]=-1;
		else
		{
			cle(A,n-len+10);
			A[0]=n-len+1;
			for(i=len;i>=1;i--) A[len-i+1]+=w[i];
			for(i=1;i<=n-len;i++) A[i]+=w[n-i+1];
			for(x=1;x<=A[0];x++) A[x+1]+=A[x]/10,A[x]%=10;
			while(A[0]>1&&A[A[0]]==0) A[0]--;
		}
		if(w[n-len+1]==0) B[0]=-1;
		else
		{
			cle(B,n-len+10);
			B[0]=n-len+1;
			for(i=1;i<=n-len;i++) B[i]+=w[n-len-i+1];
			for(i=1;i<=len;i++) B[i]+=w[n-i+1];
			for(x=1;x<=B[0];x++) B[x+1]+=B[x]/10,B[x]%=10;
			while(B[0]>1&&B[B[0]]==0) B[0]--;
		}
		if(A[0]==-1&&B[0]==-1) continue;
		//printf("%d\n",A[0]);
		if(A[0]==-1) put(B);
		if(B[0]==-1) put(A);
		if(A[0]<B[0]) put(A);
		if(A[0]>B[0]) put(B);
		
		for(i=A[0];i>=1;i--)
		{
			if(A[i]<B[i]) put(A);
			if(A[i]>B[i]) put(B);
		}
		put(A);
	}
	return 0;
}