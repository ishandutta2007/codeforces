#include<map>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
#define VFor(i,V) for (vector<int>::iterator i=V.begin();i<V.end();i++)
#define Pb push_back
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
typedef int one[N];
struct Edge {int y,nxt;} E[N*2];
struct Que
{
	int L,R,ID;
	bool operator < (const Que& B) const {return R>B.R;}
};
vector<Que> Q[N];
vector<int> Rt,Pt[N];
one I,O,C,Last,Ans,pre,Las,D;
map<string,int> M;
int n,cnt,col,tot,k,m,x,c,Time;
string s;

bool cmp(int a,int b) {return I[a]<I[b];}
void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void DFS(int x,int Fa)
{
	I[x]=++tot;
	Pt[D[x]].Pb(x);
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].y!=Fa) D[E[i].y]=D[x]+1,DFS(E[i].y,x);
	O[x]=tot;
}

one S,T;
void Add(int x,int v) {for (x++;x<=n;x+=x&-x) {if (T[x]!=Time) T[x]=Time,S[x]=0;S[x]+=v;}}
void Add_LR(int L,int R,int v) {Add(L,v),Add(R+1,-v);}
int Query(int x) {int Ans=0;for (x++;x;x-=x&-x) Ans+=T[x]==Time?S[x]:0;return Ans;}

int Lower(int d,int x)
{
	int L=0,R=Pt[d].size()-1,res=R+1;
	while (L<=R) if (I[Pt[d][Mid]]>=x) res=Mid,R=Mid-1;else L=Mid+1;
	return res;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	memset(Las,-1,sizeof(Las));
	n=IN();
	For(i,1,n+1)
	{
		cin>>s;if (x=IN()) Link(x,i);else Rt.Pb(i);
		if (M.count(s)) C[i]=M[s];else C[i]=M[s]=++col;
	}
	For(i,0,Rt.size()) DFS(Rt[i],-1);
	m=IN();
	For(i,0,m) {x=IN(),k=IN();if (D[x]+k<n) Q[D[x]+k].Pb((Que){I[x],O[x],i});}
	For(d,0,n)
	{
		sort(Pt[d].begin(),Pt[d].end(),cmp);
		For(i,0,Q[d].size())
			Q[d][i].L=Lower(d,Q[d][i].L),
			Q[d][i].R=Lower(d,Q[d][i].R+1)-1;
//		For(i,0,Pt[d].size()) printf("%d ",Pt[d][i]);puts("");
		sort(Q[d].begin(),Q[d].end());c=0,Time++;
		VFor(i,Pt[d]) pre[c]=Las[C[*i]],Las[C[*i]]=c++;
		For(i,0,Pt[d].size()) Add_LR(pre[i]+1,i,1);
		
		for (int r=Pt[d].size()-1,cur=0;~r;r--)
		{
//			For(i,0,Pt[d].size()) printf("curAns[%d..R] is %d\n",i,Query(i));
			while (cur<Q[d].size()&&Q[d][cur].R==r)
				Ans[Q[d][cur].ID]=Query(Q[d][cur].L),cur++;
			Add_LR(pre[r]+1,r,-1);
		}
		
		VFor(i,Pt[d]) Las[C[*i]]=-1;
	}
	For(i,0,m) printf("%d\n",Ans[i]);
}