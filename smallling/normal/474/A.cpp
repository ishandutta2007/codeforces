#include<cstdio>
#include<cstring>

using namespace std;

struct lhy{
	int x,y;
}a[10000];

char mp[4][20],s[10000],ch;
int l;

void work(int x,char s[])
{
	l=strlen(s);
	for(int i=0;i<l;i++)
		mp[x][i+1]=s[i],a[s[i]]=(lhy){x,i+1};
}

int main()
{
	work(1,"qwertyuiop");
	work(2,"asdfghjkl;");
	work(3,"zxcvbnm,./");
	ch=getchar();
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++)
		if(ch=='L')putchar(mp[a[s[i]].x][a[s[i]].y+1]);
		else putchar(mp[a[s[i]].x][a[s[i]].y-1]);
}