#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

const int Maxn=5000+19;
string s;
int A[Maxn][Maxn],B[Maxn][Maxn],Q,x,y;

int main()
{
	cin>>s;
	int Len=s.length();
	for (int i=0;i<Len;i++)
	{
		A[i][i]=1;
		for (int j=1;j<=i&&j<Len-i;j++)
			if (s[i-j]==s[i+j]) A[i-j][i+j]=1;else break;
	}
	for (int i=0;i<Len-1;i++)
	{
		if (s[i]==s[i+1]) A[i][i+1]=1;else continue;
		for (int j=1;j<=i&&j<Len-(i+1);j++)
			if (s[i-j]==s[i+j+1]) A[i-j][i+j+1]=1;else break;		
	}
	for (int i=0;i<Len;i++)
		for (int j=1;j<Len;j++) A[i][j]+=A[i][j-1];
	for (int R=0;R<Len;R++)
		for (int L=R;L>=0;L--)
			B[L][R]=A[L][R]+B[L+1][R];
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",B[x-1][y-1]);
	}
}