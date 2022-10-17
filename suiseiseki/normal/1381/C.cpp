#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int n,x,y;
int a[Maxn+5],b[Maxn+5];
vector<int> pos[Maxn+5];
vector<int> c;
priority_queue<pair<int,int> > q;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		while(!q.empty()){
			q.pop();
		}
		for(int i=1;i<=n+1;i++){
			pos[i].clear();
		}
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			pos[b[i]].push_back(i);
		}
		int zero;
		for(int i=1;i<=n+1;i++){
			if(pos[i].size()>0){
				q.push(make_pair((int)pos[i].size(),i));
			}
			else{
				zero=i;
			}
		}
		for(int i=1;i<=x;i++){
			pair<int,int> u=q.top();
			q.pop();
			a[pos[u.second].back()]=u.second;
			pos[u.second].pop_back();
			u.first--;
			if(u.first>0){
				q.push(make_pair(u.first,u.second));
			}
		}
		c.clear();
		while(!q.empty()){
			pair<int,int> u=q.top();
			q.pop();
			for(int i=0;i<(int)pos[u.second].size();i++){
				c.push_back(pos[u.second][i]);
			}
		}
		int num=0;
		for(int i=0;i<(int)c.size();i++){
			if(num<y-x&&b[c[i]]!=b[c[(i+(c.size()>>1))%c.size()]]){
				a[c[i]]=b[c[(i+(c.size()>>1))%c.size()]];
				num++;
			}
			else{
				a[c[i]]=zero;
			}
		}
		if(num<y-x){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i=1;i<=n;i++){
				printf("%d ",a[i]);
			}
			puts("");
		}
	}
	return 0;
}