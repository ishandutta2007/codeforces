#include<cstdio>
#include<cctype>
using namespace std;

char s[10];
int A,B;

int main()
{
	for (int i=0;i<8;i++)
	{
		scanf("%s",s);
		for (int j=0;j<8;j++)
			if (isupper(s[j])) A+=(s[j]=='Q'?9:(s[j]=='R'?5:(s[j]=='B'||s[j]=='N'?3:(s[j]=='P'?1:0))));
				else B+=(s[j]=='q'?9:(s[j]=='r'?5:(s[j]=='b'||s[j]=='n'?3:(s[j]=='p'?1:0))));
	}
	if (A>B) puts("White");else if (A<B) puts("Black");else puts("Draw");
}