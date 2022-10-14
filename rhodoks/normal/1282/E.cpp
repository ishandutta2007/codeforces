#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN][3];
typedef pair<int,int> pii;
set<pii> st;
int nxt[MAXN][2];
int x[MAXN];
vector<pii> re;
map<LL,int> mp;
int pp[MAXN];

LL hsh(int x,int y,int z)
{
	if (y>z)
		swap(y,z);
	if (x>y)
		swap(x,y);
	if (y>z)
		swap(y,z);
	return ((LL)x<<40)+((LL)y<<20)+z;
}

void init()
{
	cin>>n;
	mp.clear();
	st.clear();
	re.clear();
	for (int i=0;i<n+2;i++)
		nxt[i][0]=nxt[i][1]=0;
	pii tmp;
	for (int i=0;i<n-2;i++)
	{
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		mp[hsh(a[i][0],a[i][1],a[i][2])]=i+1;
		for (int j=0;j<3;j++)
		{
			tmp={a[i][j],a[i][(j+1)%3]};
			if (tmp.first>tmp.second)
				swap(tmp.first,tmp.second);
			if (st.count(tmp))
			{
				st.erase(tmp);
				re.push_back(tmp);
			}
			else
				st.insert(tmp);
		}
	}
	for (auto p:st)
	{
		int x=p.first;
		int y=p.second;
		if (nxt[x][0])
			nxt[x][1]=y;
		else
			nxt[x][0]=y;
		if (nxt[y][0])
			nxt[y][1]=x;
		else
			nxt[y][0]=x;
	}
	int pos=1,lst=nxt[pos][0];
	int cnt=1;
	while (1)
	{
		printf("%d ",pos);
		pp[pos]=cnt;
		x[cnt++]=pos;
		if (nxt[pos][0]==lst)
			lst=pos,pos=nxt[pos][1];
		else
			lst=pos,pos=nxt[pos][0];
		if (pos==1)
			break;
	}
	cout<<endl;
	for (int i=1;i<=n;i++)
	{
		nxt[x[i]][0]=x[i-1];
		nxt[x[i]][1]=x[i+1];
	}
	nxt[x[1]][0]=x[n];
	nxt[x[n]][1]=x[1];
}

bool cmp(pii p1,pii p2)
{
	int x1=pp[p1.second]-pp[p1.first];
	int x2=pp[p2.second]-pp[p2.first];
	if (x1<0)
		x1+=n;
	if (x2<0)
		x2+=n;
	if (x1>n/2)
		x1=n-x1;
	if (x2>n/2)
		x2=n-x2;
	return x1<x2;
}

bool visit[MAXN];

void work()
{
	for (int i=1;i<=n-2;i++)
		visit[i]=1;
	sort(re.begin(),re.end(),cmp);
	int t;
	for (auto p:re)
	{
		int x=p.first;
		int y=p.second;
		int t;
		
		if (nxt[x][0]==nxt[y][1])
		{
			t=nxt[x][0];
			nxt[x][0]=y;
			nxt[y][1]=x;
		}
		else
		{
			t=nxt[x][1];
			nxt[x][1]=y;
			nxt[y][0]=x;
		}
		int xx=mp[hsh(x,y,t)];
		cout<<xx<<' ';
		visit[xx]=0;
	}
	for (int i=1;i<=n-2;i++)
		if (visit[i])
			cout<<i;
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		init();
		work();	
	} 
	return ~~(0^_^0);
}