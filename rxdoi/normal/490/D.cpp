#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int a1,b1,a2,b2,_a1,_b1,_a2,_b2;
int A[Maxn],cA;
int B[Maxn],cB;
int ca2,ca3,cb2,cb3,_ca2,_ca3,_cb2,_cb3;

int main()
{
	scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
	_a1=a1,_b1=b1,_a2=a2,_b2=b2;
	for (int i=2;i<=sqrt(a1);i++) 
		if (a1%i==0) 
		{
			A[cA++]=i;a1/=i;
			while (a1%i==0) a1/=i,A[cA++]=i;
		}
	if (a1!=1) A[cA++]=a1;
	for (int i=2;i<=sqrt(b1);i++) 
		if (b1%i==0) 
		{
			A[cA++]=i;b1/=i;
			while (b1%i==0) b1/=i,A[cA++]=i;
		}
	if (b1!=1) A[cA++]=b1;	
	for (int i=2;i<=sqrt(a2);i++) 
		if (a2%i==0) 
		{
			B[cB++]=i;a2/=i;
			while (a2%i==0) a2/=i,B[cB++]=i;
		}
	if (a2!=1) B[cB++]=a2;	
	for (int i=2;i<=sqrt(b2);i++) 
		if (b2%i==0) 
		{
			B[cB++]=i;b2/=i;
			while (b2%i==0) b2/=i,B[cB++]=i;
		}
	if (b2!=1) B[cB++]=b2;
	sort(A,A+cA);sort(B,B+cB);
	for (int i=cA-1,j=cB-1;i>=0&&j>=0&&(A[i]!=2&&A[i]!=3||B[j]!=2&&B[j]!=3);i--,j--)
		if (A[i]!=B[j]) {puts("-1");return 0;}
	for (int i=0;i<cA;i++) ca2+=(A[i]==2),ca3+=(A[i]==3);
	for (int i=0;i<cB;i++) cb2+=(B[i]==2),cb3+=(B[i]==3);
	int Ans;
	_ca2=ca2,_cb2=cb2,_ca3=ca3,_cb3=cb3;
	if (ca3>cb3) Ans=ca3-cb3,ca3=cb3,ca2+=Ans;
		else Ans=cb3-ca3,cb3=ca3,cb2+=Ans;
	Ans+=abs(cb2-ca2);ca2=cb2=min(ca2,cb2);
	printf("%d\n",Ans);
	for (;_ca3!=ca3&&_a1%3==0;_a1/=3,_ca3--,_a1*=2,_ca2++);
	for (;_ca3!=ca3&&_b1%3==0;_b1/=3,_ca3--,_b1*=2,_ca2++);
	for (;_ca2!=ca2&&_a1%2==0;_a1/=2,_ca2--);
	for (;_ca2!=ca2&&_b1%2==0;_b1/=2,_ca2--);
	
	for (;_cb3!=cb3&&_a2%3==0;_a2/=3,_cb3--,_a2*=2,_cb2++);
	for (;_cb3!=cb3&&_b2%3==0;_b2/=3,_cb3--,_b2*=2,_cb2++);
	for (;_cb2!=cb2&&_a2%2==0;_a2/=2,_cb2--);
	for (;_cb2!=cb2&&_b2%2==0;_b2/=2,_cb2--);
	printf("%d %d\n%d %d\n",_a1,_b1,_a2,_b2);
}