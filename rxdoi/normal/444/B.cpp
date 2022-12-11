#include<set>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
const int Maxn=100000+19;
struct note
{
	int num,pos;
	bool operator < (const note& B) const {return num>B.num;}
};
int a[Maxn],b[Maxn],Dis[Maxn],nxt[Maxn];
int n,d,cnt,Last=-1,Max;
set<note> S;
LL x;

inline LL getNextX() {x=(x*37+10007)%1000000007;return x;}
inline void initAB() 
{
    for(int i=0;i<n;i++) a[i] = i + 1;
    for(int i=0;i<n;i++) swap(a[i],a[getNextX()%(i+1)]);
    for(int i=0;i<n;i++) if (i<d) b[i]=1;else b[i]=0;
    for(int i=0;i<n;i++) swap(b[i],b[getNextX()%(i+1)]);
}

int main()
{
	scanf("%d%d%I64d",&n,&d,&x);
	initAB();
	if (d<=sqrt(n))
	{
		for (int i=0;i<n;i++) if (b[i]==1) Dis[cnt++]=i;Dis[cnt]=n;
		for (int i=0;i<n;i++)
		{
			int Ans=0;
			for (int j=0;Dis[j]<=i;j++) Ans=max(Ans,a[i-Dis[j]]*b[Dis[j]]);
			printf("%d\n",Ans);
		}
	} else
	{
		S.clear();
		for (int i=0;i<n;i++)
		{
			int Ans=0;
			S.insert((note){a[i],i});
			for (set<note>::iterator j=S.begin();j!=S.end();j++)
				if (b[i-(*j).pos]) {Ans=(*j).num;break;}
			printf("%d\n",Ans);
		}
	}
}