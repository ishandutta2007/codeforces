#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
struct Edge {int y,nxt;} E[Maxn*2];
int A[Maxn];
LL F[Maxn];
int Last[Maxn],cnt,Fir,x,y,n;
vector<LL> V[Maxn];

inline int cmp(LL a,LL b) {return a>b;}
inline void Add_Edge(int x,int y) {E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;}
inline void DFS(int x,int Fa)
{
    A[x]--;F[x]=1;
    int cnt=0;LL sum=0;
    for (int i=Last[x];i!=-1;i=E[i].nxt)
    {
        int y=E[i].y;
        if (y==Fa||!A[y]) continue;
        DFS(y,x);
        cnt++;sum+=A[y];
        V[x].push_back(F[y]);
    }
    sort(V[x].begin(),V[x].end(),cmp);
    int k=min(A[x],cnt);A[x]-=k;
    for (int i=0;i<k;i++) F[x]+=V[x][i];F[x]+=k;
    LL q=min(1LL*A[x],sum);A[x]-=q;
    F[x]+=2*q;
}

int main()
{
    memset(Last,-1,sizeof(Last));
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&A[i]);
    for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Add_Edge(x,y),Add_Edge(y,x);
    scanf("%d",&Fir);A[Fir]++;
    DFS(Fir,-1);
    printf("%I64d\n",F[Fir]-1);
}