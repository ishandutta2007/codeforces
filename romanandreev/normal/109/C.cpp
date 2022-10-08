#include<cmath>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<cassert>
#include<ctime>
#include<climits>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define y1 y1_fudisghsdis
#define y0 y0_fudisghsdis
#define ws ws_fudisghsdis
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define uniq(a) {sort(all(a));(a).resize(unique(all(a))-(a).begin());}
#define uniq1(a,n) {sort(a,a+n);n=unique(a,a+n)-a;}

typedef pair<int,int> pi;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#ifdef WIN32 
	#define INT64 "%I64d"
#else
	#define INT64 "%lld"	
#endif
#define TASK_NAME "a"
const int maxn=3e5+10;
const int maxe=6e5+20;
int res[maxn];
int head[maxn];
int b[maxn];
int dp1[maxn];
int dp2[maxn];
int dp3[maxn];
int h[maxn];

ll ans;
int kl,n,x,y,z;
int next[maxe];
int cs[maxe];

int e[maxe];

int tim=0;
void add(int x,int y,int z){
	kl++;
	next[kl]=head[x];
	head[x]=kl;
	cs[kl]=z;
	e[kl]=y;
}
void dfs(int v,int pr){
	b[v]=1;
	dp1[v]=1;
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0){
			h[e[bb]]=h[v]+1;
			dfs(e[bb],bb);
			dp1[v]+=dp1[e[bb]];
		}
	}
}
void dfs1(int v,int pr){
	b[v]=1;	
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0){
			dfs1(e[bb],bb);			
			if (cs[bb]==1){
				dp2[v]+=dp1[e[bb]];
			}else {
				dp2[v]+=dp2[e[bb]];
			}
		}
	}	
}

void dfs2(int v,int pr){
	b[v]=1;
	if (pr!=-1){
		if (cs[pr]==1){	
			dp3[v]=n-dp1[v];
		} else {
			dp3[v]=dp3[e[pr^1]]+dp2[e[pr^1]]-dp2[v];
		}
	}
	vector<ll> vv;
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0){
			dfs2(e[bb],bb);
			if (cs[bb]==1)
				vv.pb(dp1[e[bb]]);
			else
				vv.pb(dp2[e[bb]]);
		}
	}
	if (pr!=-1) {
		vv.pb(dp3[v]);	
	}
	ll sum=0;
	for (int i=0;i<sz(vv);i++){		
		sum+=vv[i];
	}
	for (int i=0;i<sz(vv);i++){		
		ans+=vv[i]*(vv[i]-1);
		ans+=vv[i]*(sum-vv[i]);
	}
	//cerr<<ans<<endl;
}
int main(){
	#ifdef home
	assert(freopen(TASK_NAME".out","w",stdout));
	assert(freopen(TASK_NAME".in","r",stdin));
	#endif
	scanf("%d",&n);
	kl=1;
	for (int i=0;i<n-1;i++){
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		int fx=1;
		while (z>0){
			if (z%10!=4 && z%10!=7)
				fx=0;				
			z/=10;
		}		
		add(x,y,fx);
		add(y,x,fx);
	}
	ans=0;
	h[0]=0;
	dfs(0,-1);
	for (int i=0;i<n;i++)
		b[i]=0;
	dfs1(0,-1);
	for (int i=0;i<n;i++)
		b[i]=0;
	dfs2(0,-1);
	cout<<ans<<endl;
	#ifdef home
		cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	#endif
	return 0;
}