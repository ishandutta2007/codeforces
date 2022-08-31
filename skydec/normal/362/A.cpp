#include<stdio.h>
#include<cstring>
using namespace std;
bool gone[9][9]={false};
bool goneb[9][9]={false};
long t;
bool map[9][9]={false};
long abs(long a){if(a<0)return -a;else return a;}
char getnext()
{
	while(true)
	{
		char p=getchar();
		if(p!=' '&&p!='\n')return p;
	}
}
int main()
{
	scanf("%ld",&t);
	for(long ip=1;ip<=t;ip++)
	{
		memset(gone,0,sizeof gone);
		memset(goneb,0,sizeof goneb);
		memset(map,false,sizeof map);
		long x1,y1,x2,y2;bool f=false;
		for(long i=1;i<=8;i++)
		for(long j=1;j<=8;j++)
		{
			char p=getnext();
			if(p=='#')map[i][j]=false;
			else map[i][j]=true;
			if(p=='K')
			{
				if(!f)
				{
					x1=i;y1=j;
					f=true;
				}
				else
				{
					x2=i;y2=j;
				}
			}
		}
		bool can=false;
		if(abs(x1-x2)%4==0&&abs(y1-y2)%4==0)can=true;
		if(can)printf("YES\n");else printf("NO\n");
	}
	//for(;;);
	return 0;
}