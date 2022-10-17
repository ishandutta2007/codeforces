#include <cstdio>
#include <cstring>
#define Maxn 250
int n,mid,size[Maxn+5],val[Maxn+5],l[Maxn+5],r[Maxn+5];
bool dp[Maxn+5][2][3],vis[Maxn+5][2][3];
bool merge(bool x,bool y,bool who){
	if(x==who||y==who){
		return who;
	}
	return !who;
}
bool getdp(int pos,bool who,int skip){
	if(val[pos]!=-1){
		return val[pos]>mid;
	}
	else if(size[pos]==1){
		return merge(getdp(l[pos],0,0),getdp(r[pos],0,0),who^(skip==2));
	}
	else if(vis[pos][who][skip]){
		return dp[pos][who][skip];
	}
	bool &ans=dp[pos][who][skip];
	vis[pos][who][skip]=1;
	if(skip){
		ans=getdp(pos,!who,0);
		if(size[pos]&1){
			if(size[l[pos]]&1){
				ans=merge(ans,merge(getdp(l[pos],who,0),getdp(r[pos],!who,1+(size[l[pos]]==1&&skip==1)),!who),who);
				ans=merge(ans,merge(getdp(r[pos],who,0),getdp(l[pos],!who,1+(size[r[pos]]==1&&skip==1)),!who),who);
			}
			else{
				if(size[l[pos]]){
					ans=merge(ans,merge(getdp(l[pos],who,1+(size[r[pos]]==0&&skip==1)),getdp(r[pos],!who,0),!who),who);
				}
				if(size[r[pos]]){
					ans=merge(ans,merge(getdp(r[pos],who,1+(size[l[pos]]==0&&skip==1)),getdp(l[pos],!who,0),!who),who);
				}
			}
		}
		else{
			ans=merge(ans,merge(getdp(l[pos],who,1+(size[r[pos]]==0&&skip==1)),getdp(r[pos],who,0),who),who);
		}
	}
	else{
		if(size[pos]&1){
			if(size[l[pos]]&1){
				ans=merge(getdp(l[pos],who,1),getdp(r[pos],who,1),who);
			}
			else{
				ans=merge(getdp(l[pos],who,0),getdp(r[pos],who,0),who);
			}
		}
		else{
			ans=merge(merge(getdp(l[pos],who,0),getdp(r[pos],!who,0),!who),merge(getdp(r[pos],who,1),getdp(l[pos],!who,1),!who),who);
		}
	}
	return ans;
}
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
void dfs(int pos){
	size[pos]=0;
	if(val[pos]!=-1){
		return;
	}
	dfs(l[pos]);
	dfs(r[pos]);
	size[pos]=1+size[l[pos]]+size[r[pos]];
	if(size[r[pos]]&1){
		swap(l[pos],r[pos]);
	}
}
void init(){
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
		if(val[i]==-1){
			scanf("%d%d",&l[i],&r[i]);
		}
		else{
			l[i]=r[i]=-1;
		}
	}
	dfs(0);
}
int main(){
	int t;
	scanf("%d",&t);
	int left,right;
	while(t--){
		scanf("%d",&n);
		init();
		left=0,right=1000;
		while(left<right){
			mid=(left+right)>>1;
			memset(vis,0,sizeof vis);
			if(getdp(0,1,0)){
				left=mid+1;
			}
			else{
				right=mid;
			}
		}
		printf("%d\n",left);
	}
	return 0;
}