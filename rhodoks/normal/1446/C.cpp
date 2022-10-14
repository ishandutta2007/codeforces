#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 12100000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int son[MAXM][2];
int valid[MAXM];
int ans;
int ncnt = 1;
int n;
int a[MAXN];
void insert(int x,int id) {
    int pos = 1;
    for (int i = 30; i >=0 ; i--)
	{
        int to = ((x>>i)&1);
        if (!son[pos][to])
            son[pos][to] = ++ncnt;
        pos=son[pos][to];
    }
}

#define LS son[pos][0]
#define RS son[pos][1]

int dfs(int pos)
{
	if (LS==0 && RS==0)
	{
		valid[pos]=1;
		return valid[pos];
	}
	if (LS)
		dfs(LS);
	if (RS)
		dfs(RS);
	valid[pos]=max(valid[LS]+min(1,valid[RS]),valid[RS]+min(1,valid[LS]));
	return valid[pos];
}


int to[MAXN]; 

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		insert(a[i],i);
	}
	cout<<n-dfs(1)<<endl;
	//for (int i=1;i<=n;i++)
	//	cout<<i<<' '<<query(a[i])<<endl;
	return ~~(0^_^0);
}