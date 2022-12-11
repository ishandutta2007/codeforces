#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=99+19;
int cnt[2][Maxn],t,x,n;
char home[25],away[25],tmp[4],col[4];

int main()
{
	scanf("%s%s",home,away);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%s%d%s",&t,tmp,&x,col);
		int &y=cnt[tmp[0]=='a'][x];
		y+=col[0]=='r'?2:1;
		if (y>=2) printf("%s %d %d\n",tmp[0]=='a'?away:home,x,t),y=-200;
	}
}