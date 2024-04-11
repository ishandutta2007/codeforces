#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define M 100100
#define pb push_back
#define sz size
vector<int> v[M], chi[M];
int n, m, pa[M], dep[M], id[M];
bool cmp(int i, int j){return dep[i]>dep[j];}
bool flag[M], f[M], up[M];

int main(){
	scanf("%d %d", &n, &m);
	if(m&1){
		puts("No solution");
		return 0;
	}
	if(!m)return 0;
	int i, j, k;
	while(m--){
		scanf("%d %d", &i, &j);
		v[i].pb(j);
		v[j].pb(i);
	}
	queue<int>q;
	flag[1]=1;
	q.push(1);
	while(!q.empty()){
		k=q.front(); q.pop();
		for(i=0; i<v[k].sz(); i++){
			j=v[k][i];
			if(!flag[j]){
				flag[j]=1;
				q.push(j);
				pa[j]=k;
				chi[k].pb(j);
				dep[j]=dep[k]+1;
			}
		}
	}
	for(i=1; i<=n; i++)id[i]=i;
	sort(id+1, id+n+1, cmp);


	for(int ii=1; ii<=n; ii++){
		i=id[ii];
		f[i]=1;
		bool r=0;
		for(j=0; j<chi[i].sz(); j++){
			k=chi[i][j];
			if(!up[k]){
				up[k]=1;
				if(!r)printf("%d %d ", k, i);
				else printf("%d\n", k);
				r^=1;
			}
		}
		for(j=0; j<v[i].sz(); j++){
			k=v[i][j];
			if(f[k] || up[k] || k==pa[i])continue;
			if(!r)printf("%d %d ", k, i);
			else printf("%d\n", k);
			r^=1;
		}
		if(!r){
			up[i]=0;
		}else{
			up[i]=1;
			printf("%d\n", pa[i]);
		}
	}
	return 0;
}