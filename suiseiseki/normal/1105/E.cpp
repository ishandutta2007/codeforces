#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
int G[100][100];
int ans,cnt[100],group[100],n,m,vis[100];
map<string,int> mp;
int tot = 0;
struct node{
	int op;
	string s;
}Q[maxn];
vector<int> v;
bool dfs(int u,int pos){
    int i,j;
    for(i=u+1;i<=tot;i++){
        if(cnt[i]+pos<=ans) return 0;
        if(G[u][i]){
            for(j=0;j<pos;j++) if(!G[i][vis[j]]) break; 
            if(j==pos){
            	vis[pos]=i;
                if(dfs(i,pos+1)) return 1;    
            }    
        }
    }    
    if(pos>ans){
        for(i=0;i<pos;i++) group[i] = vis[i];
        ans = pos;
        return 1;    
    } 
    return 0;
} 
void maxclique(){
    ans=-1;
    for(int i=tot;i>0;i--){
        vis[0]=i;
        dfs(i,1);
        cnt[i]=ans;
    }
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int op;
		string tmp;
		scanf("%d",&op);
		if(op==1) Q[i].op = op;
		else{
			cin>>tmp;
			Q[i].op = op;
			Q[i].s = tmp;
			if(!mp[tmp]) mp[tmp] = ++tot;
		}
	}
	memset(G,INF,sizeof(G));
	for(int i=1;i<=n;i++){
		if(Q[i].op==1){
			for(int j=0;j<(int)v.size();j++){
				for(int k=j+1;k<(int)v.size();k++){
					G[v[k]][v[j]] = 0;
					G[v[j]][v[k]] = 0;
				}
			}
			v.clear();	
		}
		else{
		
			v.push_back(mp[Q[i].s]);
		}
	}
	for(int i=0;i<(int)v.size();i++){
		for(int j=i+1;j<(int)v.size();j++){
			G[v[i]][v[j]] = 0;
			G[v[j]][v[i]] = 0;
		}
	}
	maxclique();
	if(ans<0) ans = 0;
	printf("%d\n",ans);
	return 0;
}