#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N=1005,M=100005,mod=1e9+7;
inline void gmin(int &x,int y){if(x>y) x=y;}
inline void gmax(int &x,int y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

int n,m,k,a[N],d[N<<2];
bool vis[N];
queue<int> q;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		int x;scanf("%d",&x);
		if(!vis[x]) a[++m]=x-n;
		vis[x]=1;
	}
	for(int i=1;i<=m;i++) d[a[i]+1000]=1,q.push(a[i]+1000);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=m;i++)
			if(x+a[i]>0&&!d[x+a[i]]) d[x+a[i]]=d[x]+1,q.push(x+a[i]);
	}
	printf("%d\n",d[1000]?d[1000]:-1);
	return 0;
}