#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 2010;
struct node{
	int id,val;
}e[MAXN];int n;
bool cmp(node a,node b){
	return a.val<b.val;
}
int op[MAXN];
int vis[MAXN];
const int INF = 0x7f7f7f7f;
int maxx=INF;
int ans=INF;
void up(){
	bool check=true;
	for(int i=2;i<=2*n;i++){
		int p=e[i].id;
		for(int j=1;j<=maxx;j++){
			if(op[j]==1){
				if(p&1) p++;else p--;
			}
			else{
				if(p>n) p-=n;else p+=n;
			}
		}
		if(p!=i){
			check=false;break;
		}
	}
	if(check){
		ans=min(ans,maxx);
	}
}
void dfs(int s,int t,int step){
	if(s==t){
		maxx=step-1; 
		up();
		return;
	}
	//if(step>=ans) return;
	if(s&1){
		if(!vis[s+1]){
			vis[s+1]=1;op[step]=1;
			dfs(s+1,t,step+1);
			vis[s+1]=0;
		}
	}
	else{
		if(!vis[s-1]){
			vis[s-1]=1;op[step]=1;dfs(s-1,t,step+1);vis[s-1]=0;
		}
	}
	if(s<=n){
		if(!vis[s+n]){
			vis[s+n]=1;op[step]=2;dfs(s+n,t,step+1);vis[s+n]=0;
		}
	}
	else{
		if(!vis[s-n]){
			vis[s-n]=1;op[step]=2;dfs(s-n,t,step+1);vis[s-n]=0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n*2;i++){
		e[i].id=i;cin>>e[i].val;
	}
	sort(e+1,e+n*2+1,cmp);
	int num=0;
	vis[e[1].id]=1;
	dfs(e[1].id,1,1);
	if(ans!=INF){
		cout<<ans<<'\n';
	}
	else{
		cout<<"-1\n";
	}
}