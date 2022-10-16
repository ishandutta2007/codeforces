#include <stdio.h>
#include <string.h> 
#include <queue>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
/*inline int read1d()
{
	char c=getchar();
	while(c<48||c>57)c=getchar();
	return c-48;
}*/
int a[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
int ab,cd,h,m;
void gen()
{
	cd++;
	if(cd>=m)cd=0,ab++;
	if(ab>=h)ab=0;
}
int ok()
{
	int aa=ab/10,bb=ab%10,cc=cd/10,dd=cd%10;
	if(a[aa]!=-1)aa=a[aa];else return 0;
	if(a[bb]!=-1)bb=a[bb];else return 0;
	if(a[cc]!=-1)cc=a[cc];else return 0;
	if(a[dd]!=-1)dd=a[dd];else return 0;
	int fab=dd*10+cc,fcd=bb*10+aa;
	return fab<h&&fcd<m;
}
signed main()
{
	int T=read();
	while(T--)
	{
		h=read(),m=read(),ab=read(),cd=read();
		while(1)
		{
			if(ok())break;
			gen();
		}
		printf("%02d:%02d\n",ab,cd);
	}
}