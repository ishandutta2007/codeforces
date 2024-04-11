#include<bits/stdc++.h>
using namespace std;
const int maxn = 400500, maxm = 400500;
int x[maxm], y[maxm];
int mark[maxn],st[maxn],n,m,t,ans,cnt,f[400500],num[400500],f2[400500],num2[400500];
bool vis[10050000];
vector<int> lv[maxn],rv[maxn],clr,v[maxn];

void dfs1(int x){
	vis[x]=1;
	for(auto i:lv[x]){
		if(i==x){f2[x]=1;}
		if(!vis[i]){
			dfs1(i);
		}
	}
	st[++t]=x;
}

void dfs2(int x){
	mark[x]=t;
	for(auto i:rv[x]){
		if(!mark[i])dfs2(i);
	}
}

void dfs3(int x){
	vis[x]=1;
	for(auto i:v[x]){
		if(vis[i]){continue;}
		dfs3(i);
	}
}


int i,j,k,T;
queue<int> q;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n+1;i++){
			vector<int> cl1,cl2,cl3;
			swap(lv[i],cl1);
			swap(rv[i],cl2);
			swap(v[i],cl3);
			f[i]=0;
			num[i]=0;
		}
		memset(vis,0,n*4+50);
		memset(mark,0,n*4+50);
		memset(st,0,n*4+50);
		memset(f2,0,n*4+50);
		memset(num2,0,n*4+50);
		t=0;
		for(i=1;i<=m;i++){
			scanf("%d%d",&x[i],&y[i]);
			lv[x[i]].push_back(y[i]);
			rv[y[i]].push_back(x[i]);
		}

		for(i=1;i<=n;i++)if(!vis[i]){dfs1(i);}
		t=0;
		for(i=n;i>=1;i--)if(!mark[st[i]]){t++;dfs2(st[i]);}
		f[mark[1]]=1;
		for(int i=1;i<=n;i++){
			num[mark[i]]++;
			if(f2[i]){f[mark[i]]=-1;}
			//printf("a%d %d\n",i,mark[i]);
		}
		
		for(i=1;i<=t;i++){
			if(num[i]>1){f[i]=-1;}
		}
		for(i=1;i<=m;i++){
			if(mark[x[i]]==mark[y[i]]){continue;}
			v[mark[x[i]]].push_back(mark[y[i]]);
		}
		memset(vis,0,n*4+50);
		dfs3(mark[1]);
		for(i=1;i<=m;i++){
			if(mark[x[i]]==mark[y[i]]||!vis[mark[x[i]]]){continue;}
			num2[mark[y[i]]]++;
		}
		q.push(mark[1]);
		while(!q.empty()){
			int x=q.front();q.pop();
			//printf("a%d\n",x);
			for(auto i:v[x]){
				if(f[x]==-1){f[i]=-1;}
				if(f[i]!=-1){f[i]+=f[x];if(f[i]>2){f[i]=2;}}
				num2[i]--;
				if(!num2[i]){
					q.push(i);
				}
			}
		}
		for(i=1;i<=n;i++){
			j=mark[i];
			if(!vis[j]){printf("0 ");continue;}
			if(f[j]==1){printf("1 ");continue;}
			if(f[j]>1){printf("2 ");continue;}
			if(f[j]==-1){printf("-1 ");continue;}
		}
		puts("");
	}
}