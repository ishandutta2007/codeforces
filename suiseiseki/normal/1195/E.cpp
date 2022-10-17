#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 3000
int n,m,a,b;
ll g0,x,y,z;
int mp[Maxn+5][Maxn+5];
int mn[Maxn+5][Maxn+5];
int ans[Maxn+5][Maxn+5];
deque<int> q;
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	cin>>g0>>x>>y>>z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[i][j]=g0;
			g0=(g0*x%z+y)%z;
		}
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()){
			q.pop_front();
		}
		for(int j=1;j<b;j++){
			while(!q.empty()&&mp[i][j]<= mp[i][q.front()]){
				q.pop_front();
			}
			while(!q.empty()&&mp[i][j]<=mp[i][q.back()]){
				q.pop_back();
			}
			q.push_back(j);
		}
		for(int j=b;j<=m;j++){
			while(!q.empty()&&(mp[i][j]<=mp[i][q.front()]||j-q.front()+1>b)){
				q.pop_front();
			}
			while(!q.empty()&&(mp[i][j]<=mp[i][q.back()]||j-q.front()+1>b)){
				q.pop_back();
			}
			q.push_back(j);
			mn[i][j]=mp[i][q.front()];
		}
	}
	for(int i=1;i<=m;i++){
		while(!q.empty()){
			q.pop_front();
		}
		for(int j=1;j<a;j++){
			while(!q.empty()&&mn[j][i]<=mn[q.front()][i]){
				q.pop_front();
			}
			while(!q.empty()&&mn[j][i]<=mn[q.back()][i]){
				q.pop_back();
			}
			q.push_back(j);
		}
		for(int j=a;j<=n;j++){
			while(!q.empty()&&(mn[j][i]<=mn[q.front()][i]||j-q.front()+1>a)){
				q.pop_front();
			}
			while(!q.empty()&&(mn[j][i]<=mn[q.back()][i]||j-q.front()+1>a)){
				q.pop_back();
			}
			q.push_back(j);
			ans[j][i]=mn[q.front()][i];
		}
	}
	ll an=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			an+=ans[i][j];
		}
	}
	cout<<an<<endl;
	return 0;
}