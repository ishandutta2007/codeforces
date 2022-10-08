#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
int n,m,p[N];bool v[N];
int main()
{
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		char s[5];int x;
		scanf("%s%d",s,&x);
		if(s[0]=='+')
			if(v[x])puts("Already on");else
			{
				bool F=1;int S=0;
				for(int i=2;i*i<=x;i++)if(x%i==0)
				{
					if(p[i]){F=0,S=p[i];break;}
					if(p[x/i]){F=0,S=p[x/i];break;}
				}
				if(x>=2&&p[x])F=0,S=p[x];
				if(!F){printf("Conflict with %d\n",S);continue;}
				puts("Success");
				for(int i=2;i*i<=x;i++)if(x%i==0)
					p[i]=p[x/i]=x;
				if(x>=2)p[x]=x;
				v[x]=1;
			}else
			if(!v[x])puts("Already off");else
			{
				puts("Success");
				for(int i=2;i*i<=x;i++)
					if(x%i==0)p[i]=0,p[x/i]=0;
				if(x>=2)p[x]=0;
				v[x]=0;
			}
	}
	return 0;
}