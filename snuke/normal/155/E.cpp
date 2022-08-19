#include<cstdio>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 1000005, MG = MX<<1, INF = 100000000;

int head[MX], next[MG], to[MG], g;
P gr[MX];
int st[MG], s;
int w[MG], v[MG], o[MG];
ll cnt[MG];


int main(){
	int n, m, a, b;
	scanf("%d%d",&n,&m);
	
	rrep(i,n) head[i] = -1;
	
	rep(i,m){
		scanf("%d%d",&a,&b);
		next[g] = head[a]; head[a] = g; to[g++] = b;
		next[g] = head[b]; head[b] = g; to[g++] = a;
	}
	
	m = n*2;
	rrep(i,m) st[s++] = i;
	o[0] = n*2;
	
	rrep(i,n){
		a = gr[i].se;
		w[a] = i; v[a] = st[--s];
		gr[i].se = v[a];
		o[a]--; o[v[a]]++;
		if(!o[a]) st[s++] = a;
		
		for(int j = head[i]; j != -1; j = next[j]){
			a = gr[to[j]].fi;
			if(w[a]!=i){
				w[a] = i; v[a] = st[--s];
			}
			gr[to[j]].fi = v[a];
			o[a]--; o[v[a]]++;
			if(!o[a]) st[s++] = a;
			
			a = gr[to[j]].se;
			if(w[a]!=i){
				w[a] = i; v[a] = st[--s];
			}
			gr[to[j]].se = v[a];
			o[a]--; o[v[a]]++;
			if(!o[a]) st[s++] = a;
		}
		
		//rrep(i,n)printf("%d %d\n",gr[i].fi,gr[i].se);
	}
	
	rrep(i,n){
		cnt[gr[i].fi]++;
		cnt[gr[i].se]++;
	}
	
	ll ans = 0;
	m++;
	rep(i,m){
		ans += cnt[i]*(cnt[i]-1)/2;
	}
	
	cout << ans;
	
	return 0;
}