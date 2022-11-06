#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>
 
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;
 
const int N = 1000001;
int n,m,x,y;
vector<int> v[N];
 
queue<int> q;
int dis[N];
int prv[N];
bool vst[N];
bool ans[N]; 
int idx;
 
pii Z={0,0};
pii dfs(int cur, int prv, int h) {
	if(cur==h) return Z;
	if(vst[cur]) return {cur, prv};
	vst[cur]=true;
	for(int nxt : v[cur]) {
		if(nxt==prv) continue;
		pii temp=dfs(nxt, cur, h);
		if(temp!=Z) return temp;
	}
	return Z;
}
void print();
bool findCycle(int h) {
	for(int i=1; i<=n; i++) vst[i]=false;
	for(int i=1; i<=n; i++) {
		if(vst[i]) continue;
		pii c=dfs(i,0,h);
		if(c!=Z){
			//i->c min path
			int s=c.first, e=c.second;
			for(int j=1; j<=n; j++) dis[j]=INF;
			dis[s]=0;
			q.push(s);
			while(!q.empty()) {
				int cur=q.front(); q.pop();
				for(int nxt : v[cur]) {
					if(cur==s && nxt==e) continue;
					if(cur==h) continue;
					if(dis[nxt]==INF) dis[nxt]=dis[cur]+1, prv[nxt]=cur, q.push(nxt);
				}
			}
			for(int j=e; j!=s; j=prv[j]) ans[j]=true;
			ans[s]=true;
			print();
			return true;
		}
	}
	return false;
}
void print() {
	printf("Yes\n");
	int cnt=0;
	for(int i=1; i<=n; i++) if(!ans[i]) cnt++;
	printf("%d\n", cnt);
	for(int i=1; i<=n; i++) if(!ans[i]) printf("%d ", i);
	printf("\n");
}
void mark(int cur) {
	if(ans[cur]) return;
	ans[cur]=true;
	for(int nxt : v[cur]) mark(nxt);
}
void unmark(int cur, int x, int y) {
	if(cur==x || cur==y) return;
	if(!ans[cur]) return;
	ans[cur]=false;
	for(int nxt : v[cur]) unmark(nxt,x,y);
}
void case1() {
	for(int i=1; i<=n; i++) {
		if(sz(v[i])%3==1) {
			for(int i=1; i<=n; i++) dis[i]=INF;
			dis[i]=0;
			q.push(i);
			while(!q.empty()) {
				int cur=q.front(); q.pop();
				for(int nxt : v[cur]) if(dis[nxt]==INF) dis[nxt]=dis[cur]+1, prv[nxt]=cur, q.push(nxt);
			}
			
			int tt=INF;
			for(int j=1; j<=n; j++) {
			    if(i!=j && sz(v[j])%3==1) tt=min(tt, dis[j]);
			}
			if(tt==n-1) {printf("No\n"); return;}
			
			for(int j=1; j<=n; j++) {
				if(i!=j && sz(v[j])%3==1 && dis[j]==tt) {
					
					for(int c=j; c!=i; c=prv[c]) {
						ans[c]=true;
					}
					ans[i]=true;
					print();
					return;
				}
			}
			printf("No\n");
			return;
		}
	}
}
void case2() {
	for(int i=1; i<=n; i++) if(sz(v[i])%3==1) {idx=i; break;}

	if(findCycle(idx)) return;

	for(int i=1; i<=n; i++) {
		if(i==idx) continue;
		if(sz(v[i])>3) {
			for(int i=1; i<=n; i++) ans[i]=true;
			int c=0;
			for(int j=0; c<3; j++) {
				if(v[i][j]==idx) continue;
				unmark(v[i][j], i, idx);
				c++;
			}
			print();
			return;
		}
	}
	if(sz(v[idx])==4) {printf("No\n"); return;} //clear
	ans[idx]=true;
	int t=0;
	for(int i=0; t<2; i++) {
		if(ans[v[idx][i]]) continue;
		mark(v[idx][i]);
		t++;
	}
	print();
}
void case3() {
	bool flag=true;
	for(int i=1; i<=n; i++) if(sz(v[i])!=2) {flag=false; break;}
	if(flag) {printf("No\n"); return;}
	findCycle(0);
}
void proc() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) v[i].clear(), ans[i]=false;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	if(n==1) {printf("No\n"); return;}
	for(int i=1; i<=n; i++) {
		if(sz(v[i])%3==0) {
			ans[i]=true;
			print();
			return;
		}
	}
 
	int cnt=0;
	for(int i=1; i<=n; i++) if(sz(v[i])%3==1) cnt++;
	if(cnt>1) case1();
	else if(cnt==1) case2();
	else case3();
	
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}