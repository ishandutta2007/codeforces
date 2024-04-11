#include <cstdio>
using namespace std;
struct word
{
	int i,j;
};
word rules[10][50];
int ruletot[10];
int n,q,i,ans,u,v,w;
bool anses[65536];
int s[10];
inline int get()
{
	return s[1]+s[2]*6+s[3]*36+s[4]*216+s[5]*1296+s[6]*7776;
}
inline void find(int dep)
{
	if (dep==n)
	{
		if (!anses[get()])
		{
			ans++;
			anses[get()]=1;
		}
		return;
	}
	int v=s[dep];
	int i;
	for (i=1;i<=ruletot[v];i++)
	{
		s[dep]=rules[v][i].j;
		s[dep+1]=rules[v][i].i;
		find(dep+1);
	}
	s[dep+1]=0;
	s[dep]=v;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (i=1;i<=q;i++)
	{
		while (scanf("%c",&u)==1&&u!=10);
		scanf("%c%c %c",&u,&v,&w);
		w-=96;
		u-=96;
		v-=96;
		ruletot[w]++;
		rules[w][ruletot[w]].i=u;
		rules[w][ruletot[w]].j=v;
	}
	s[1]=1;
	find(1);
	printf("%d\n",ans);
	return 0;
}