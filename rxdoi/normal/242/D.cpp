#include<set>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mp make_pair
#define Pb push_back
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
struct Edge {int y,nxt;} E[N*2];
int Last[N],cur[N],x,cnt,n,m;
vector<int> V;

typedef pair<int,int> Pii;
set<Pii> S;
typedef set<Pii>::iterator It;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN();
	For(i,0,m) Link(IN(),IN());
	For(i,1,n+1) S.insert(Mp(x=IN(),i)),cur[i]=x;
	
//	for (It i=S.begin();i!=S.end();i++) printf("%d %d\n",i->first,i->second);
	
	for (It it=S.begin();!S.empty()&&it->first<=0;S.erase(it),it=S.begin())
	{
		if (it->first==0)
		{
			V.Pb(it->second);
			for (int i=Last[it->second];~i;i=E[i].nxt)
				if (cur[E[i].y]>=0)
				{
					S.erase(Mp(cur[E[i].y],E[i].y)),
					cur[E[i].y]--,
					S.insert(Mp(cur[E[i].y],E[i].y));
				}
		}
//		puts("");puts("");
//	for (It i=S.begin();i!=S.end();i++) printf("%d %d\n",i->first,i->second);
	}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);puts("");
}