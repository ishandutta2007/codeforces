#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=2e5+19;
typedef long long LL;
LL C[Maxn],Ans[Maxn];
vector<int> V[Maxn];
int n,m,now,A[Maxn],Dis[Maxn],cnt[Maxn];
struct Que
{
	int L,R,ID;
	bool operator < (const Que& B) const {return L<B.L;}
} Q[Maxn];

inline void Add(int x,int v) {for (;x<=n;x+=x&-x) C[x]+=v;}
inline LL Sum(int x) {LL Ans=0;for (;x;x-=x&-x) Ans+=C[x];return Ans;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),Dis[A[i]]=i;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
		{
			int x=Dis[i],y=Dis[j];
			if (x>y) swap(x,y);
			cnt[y]++;V[x].push_back(y);
		}
	for (int i=1;i<=n;i++) Add(i,cnt[i]);
	for (int i=0;i<m;i++) scanf("%d%d",&Q[i].L,&Q[i].R),Q[i].ID=i;
	sort(Q,Q+m);
	for (int L=1;L<=n;L++)
	{
		for (;Q[now].L==L;now++) Ans[Q[now].ID]=Sum(Q[now].R);
		for (int i=0;i<V[L].size();i++) Add(V[L][i],-1);
	}
	for (int i=0;i<m;i++) printf("%I64d\n",Ans[i]);
}