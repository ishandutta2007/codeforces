#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e5+19;
char s[Maxn][10];
int n,cbig[10];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	for (int i=0;i<strlen(s[1]);i++)
		if (s[1][i]=='?') s[1][i]=(!i?'1':'0');
	for (int i=2;i<=n;i++)
	{
		if (strlen(s[i])<strlen(s[i-1])) {puts("NO");return 0;}
		if (strlen(s[i])>strlen(s[i-1]))
		{
			for (int j=0;j<strlen(s[i]);j++)
				if (s[i][j]=='?') s[i][j]=(!j?'1':'0');
			continue;
		}
		int Len=strlen(s[i]),x=0;
		for (int j=Len-1;j>=0;j--)
			if ((s[i][j]=='?'?'9':s[i][j])<s[i-1][j]) cbig[j]=0;
				else if ((s[i][j]=='?'?'9':s[i][j])>s[i-1][j]) cbig[j]=1;
					else cbig[j]=(j!=Len-1&&cbig[j+1]);
		for (int j=0;j<Len;j++)
		{
			if (s[i][j]=='?')
				if (x) s[i][j]='0';
					else 
					{
						if (j!=Len-1&&cbig[j+1]) {s[i][j]=s[i-1][j];continue;}
						if (s[i-1][j]=='9') {puts("NO");return 0;}
						s[i][j]=s[i-1][j]+1;
					}
			if (s[i][j]>s[i-1][j]) x=1;
		}
	}
	for (int i=2;i<=n;i++)
		if (strlen(s[i])==strlen(s[i-1])&&strcmp(s[i],s[i-1])!=1) {puts("NO");return 0;}
	puts("YES");
	for (int i=1;i<=n;i++) printf("%s\n",s[i]);
}