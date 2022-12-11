#include<cstdio>
#include<string>
using namespace std;

char c[1000+19];
string s,tmp;
int Len,YES,change,p,A[1000+19];

int main()
{
	scanf("%d%d",&Len,&p);
	scanf("%s",c);
	for (int i=1;i<=Len;i++) A[i]=c[i-1]-'a'+1;
	if (Len==1) 
	{
		if (A[1]==p) puts("NO");else putchar(A[1]+'a');
		return 0;
	}
	while (!A[0])
	{
		if (!change)
		{
			int j=Len;
			while (A[j]==p) j--;
			A[j]++;
			for (int i=j+1;i<=Len;i++) A[i]=1;
		} else change=0;
		int Flag=1;
		for (int i=1;i+1<=Len;i++)
			if (A[i]==A[i+1]) 
			{
				Flag=0;
				int j=i+1;
				while (A[j]==p) j--;A[j]++;
				for (int k=j+1;k<=Len;k++) A[k]=1;change=1;
			}
		if (Flag)
			for (int i=1;i+2<=Len;i++)
				if (A[i]==A[i+2]) 
				{
					Flag=0;
					int j=i+2;
					while (A[j]==p) j--;A[j]++;
					for (int k=j+1;k<=Len;k++) A[k]=1;change=1;
				}
		if (Flag) {YES=1;break;}
	}
	if (YES)
		for (int i=1;i<=Len;i++) putchar(A[i]+'a'-1);
	else puts("NO");
}