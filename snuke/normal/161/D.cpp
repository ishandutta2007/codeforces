#include<cstdio>
#include<algorithm>
#include<iostream>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 50005, MG = 100005, INF = 1000000000;

int n, k;
ll ans;
int head[MX], next[MG], to[MG], co[MG], g;

void edge(int a, int b, int c){
	next[g] = head[a]; head[a] = g; to[g] = b; co[g++] = c;
}

bool cent[MX];
int sub[MX];
P d[505], o[MX];
int di, oi;

void csub(int v, int p){
	sub[v] = 1;
	for(int i = head[v]; i != -1; i = next[i]){
		if(cent[to[i]] || to[i] == p) continue;
		csub(to[i],v);
		sub[v] += sub[to[i]];
	}
}

P ccen(int v, int p, int t){
	P m = P(INF,-1);
	int x = t-sub[v];
	for(int i = head[v]; i != -1; i = next[i]){
		if(cent[to[i]] || to[i] == p) continue;
		m = min(m,ccen(to[i],v,t));
		x = max(x,sub[to[i]]);
	}
	
	return min(m,P(x,v));
}


void enu(int v, int p, int dis, int city){
	if(dis > k) return;
	o[oi++] = P(dis,city);
	for(int i = head[v]; i != -1; i = next[i]){
		if(cent[to[i]] || to[i] == p) continue;
		enu(to[i],v,dis+co[i],city+1);
	}
}


void sol(int v){
	csub(v,-1);
	int c = ccen(v,-1,sub[v]).se;
	cent[c] = true;
	
	for(int i = head[c]; i != -1; i = next[i]){
		if(cent[to[i]]) continue;
		sol(to[i]);
	}
	
	di--;
	d[0] = P(di,1);
	for(int i = head[c]; i != -1; i = next[i]){
		if(cent[to[i]]) continue;
		oi = 0;
		enu(to[i],c,co[i],1);
		rep(j,oi){
			int x = k-o[j].fi;
			if(d[x].fi == di){
				ans += d[x].se;
			}
		}
		
		rep(j,oi){
			int x = o[j].fi;
			if(d[x].fi == di){
				d[x].se++;
			} else {
				d[x] = P(di,1);
			}
		}
	}
	
	cent[c] = false;
}


int main(){
	scanf("%d%d",&n,&k);
	
	int ina, inb;
	rrep(i,n) head[i] = -1;
	rep(i,n-1){
		scanf("%d%d",&ina,&inb);
		edge(ina,inb,1);
		edge(inb,ina,1);
	}
	
	ans = 0;
	di = 1;
	sol(1);
	
	cout << ans;
	return 0;
}