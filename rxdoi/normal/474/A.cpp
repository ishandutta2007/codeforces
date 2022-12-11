#include<cstdio>
#include<cstring>
using namespace std;

char key[3][30]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
char c[5],s[100+19];

int main()
{
	scanf("%s%s",c,s);
	for (int n=0;n<strlen(s);n++)
	{
		int x,y;
		for (int i=0;i<3;i++)
			for (int j=0;j<10;j++)
				if (key[i][j]==s[n]) x=i,y=j;
		putchar(key[x][y+(c[0]=='L'?1:-1)]);
	}
}