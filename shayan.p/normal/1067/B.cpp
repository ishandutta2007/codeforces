// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
int h[maxn],pr[maxn];
int n,k;

void dfs(int u,int par=-1){
    pr[u]=par;
    for(int y:v[u]){
	if(y!=par){
	    h[y]=h[u]+1;
	    dfs(y,u);
	}
    }
}

void dfs_check(int u,int par=-1){
    int D=sz(v[u])-(par!=-1);
    if((D!=0 && D<3) || (D==0 && h[u]!=k)){
	printf("No\n");
	exit(0);
    }
    for(int y:v[u]){
	if(y!=par){
	    h[y]=h[u]+1;
	    dfs_check(y,u);
	}
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB(b);
	v[b].PB(a);
    }
    h[1]=0;
    dfs(1);
    int id1=1;
    for(int i=1;i<=n;i++){
	if(h[id1]<h[i])
	    id1=i;
    }
    h[id1]=0;
    dfs(id1);
    int id2=1;
    for(int i=1;i<=n;i++){
	if(h[id2]<h[i])
	    id2=i;
    }
    if(h[id2]!=2*k){
	printf("No\n");
	return 0;
    }
    int r=id2;
    for(int i=0;i<k;i++){
	r=pr[r];
    }
    h[r]=0;
    dfs_check(r);
    printf("Yes\n");
}