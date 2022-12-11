#include<cstdio>
#include<string>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100000+19;
string s;
int L[N],R[N],Len,Ans,t;

bool Check(int L1,int R1,int L2,int R2)
{
	if (R1-L1!=R2-L2) return R1-L1>R2-L2;
	for (int i=0;i<=R1-L1;i++) if (s[L1+i]!=s[L2+i]) return s[L1+i]>s[L2+i];
	return 1;
}

int main()
{
	cin>>s;Len=s.length();
	while (t+1<Len&&s[t+1]=='0') t++;
	Ans=1;
	for (int i=t+1;i<Len;i++)
	{
		int j=i;
		while (j+1<Len&&s[j+1]=='0') j++;
		if (!Check(0,i-1,i,j)) Ans=1;else Ans++;
		i=j;
	}
	printf("%d\n",Ans);
}