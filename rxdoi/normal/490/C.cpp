#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e6+19;
char s[Maxn];
int a,b,x,t,can1[Maxn],can2[Maxn];

int main()
{
	scanf("%s",s);
	int Len=strlen(s);
	scanf("%d%d",&a,&b);
	if (s[0]=='0') {puts("NO");return 0;}
	x=0;
	for (int i=0;i<Len;i++)
	{
		x=(x*10+s[i]-'0')%a;
		can1[i]=(x==0);
	}
	x=0;t=1;
	for (int i=Len-1;i>=0;i--)
	{
		x=((s[i]-'0')*t+x)%b;
		t=t*10%b;
		can2[i]=(x==0);
	}
	for (int i=0;i<Len-1;i++)
		if (can1[i]&&can2[i+1]&&s[i+1]!='0') 
		{
			puts("YES");
			for (int j=0;j<=i;j++) printf("%c",s[j]);puts("");
			for (int j=i+1;j<Len;j++) printf("%c",s[j]);puts("");
			return 0;
		}
	puts("NO");
}