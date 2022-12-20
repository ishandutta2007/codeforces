#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define N 120000
using namespace std;
const double pi=acos(-1);
int n,m,bfs[N],l,r,bo[N],pos[N],key[N],be[N],tot;
VI E[10][N];

void prep(){
	bfs[l=r=1]=n-1;
	bo[n-1]=1;
	while(l<=r){
		int x=bfs[l++];
		for(int i:E[0][x])if(!bo[i]){
			pos[i]=x;
			key[i]=0;
			bo[i]=1;
			bfs[++r]=i;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		E[k][x].pb(y);
		E[k][y].pb(x);
	}
	memset(bo,0,sizeof(bo));
	prep();
	rep(i,1,r)be[i]=1;
	tot=1;
	l=1;
	for(;;){
		if(bo[0]==1){
			VI ans,pq;
			for(int i=0;i!=n-1;i=pos[i])ans.pb(key[i]),pq.pb(i);
			pq.pb(n-1);
			reverse(ans.begin(),ans.end());
			bool flag=0;
			for(auto i:ans){
				if(i==0 && !flag)continue;
				printf("%d",i);
				flag=1;
			}
			if(!flag)printf("0");
			puts("");
			printf("%d\n",SZ(pq));
			for(auto i:pq)printf("%d ",i);
			return 0;
		}
		int k=l;
		while(be[k]==be[l])k++;
		rep(_,0,9){
			tot++;
			rep(i,l,k-1){
				int x=bfs[i];
				for(int j:E[_][x])if(!bo[j]){
					bo[j]=1;
					bfs[++r]=j;
					be[r]=tot;
					pos[j]=x;
					key[j]=_;
				}
			}
		}
		l=k;
	}
	puts("fuck");
}