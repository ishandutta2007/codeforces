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
int n,m;
int x[N];
vector<vector<int>> cnt;
vector<pair<vector<int>,int>> v;

ll ans=0;
vector<vector<int>> w;
void cal(int x, int y) {
	w.clear();
	for(int i=x; i<y; i++) w.push_back(cnt[v[i].second]);

	sort(all(w));
	int num=sz(w.back());

	int cur=0;
	while(cur<sz(w)) {
		int sum=0;
		for(int e : w[cur]) sum+=e;
		if(sum) break;
		cur++;
	}
	ans+=1ll*cur*(cur-1)/2;

	int ss=cur;
	int idx=sz(w)-1;
	ll t=0;
	while(cur<sz(w)) {
		int s=cur;
		while(cur<sz(w) && w[s]==w[cur]) cur++;
		
	
		bool f2=false;
		while(idx>=ss) {
			bool flag=true;
			for(int i=0; i<num; i++) {
				if(w[idx][i]+w[s][i]>m) {idx--; flag=false; break;}
				if(w[idx][i]+w[s][i]<m) {f2=true; break;}
			}
			if(flag) break;
			if(f2) break;
		}
		if(f2) continue;
		
		int e=idx;
		while(idx>=ss && w[idx]==w[e]) idx--;
		if(w[e]==w[s]) ans+=1ll*(cur-s)*(cur-s-1)/2;
		else t+=1ll*(cur-s)*(e-idx);
	}
	ans+=t/2;
}
void make(int r) {
	vector<int> temp;
	int cur=x[r];
	for(int i=2; i+i<=cur; i++) {
		if(cur%i) continue;
		int c=0;
		while(!(cur%i)) cur/=i, c++;
		
		c%=m;
		if(c) cnt[r].push_back(c), temp.push_back(i);
	}

	if(cur>1) {temp.push_back(cur); cnt[r].push_back(1);}
	v.push_back({temp,r});
}
int main(void){
	scanf("%d%d", &n, &m); cnt.resize(n);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	for(int i=0; i<n; i++) make(i);

	sort(all(v));

	int cur=0;
	while(cur<n) {
		int s=cur;
		while(cur<n && v[cur].first==v[s].first) cur++;
		cal(s, cur);
	}
	printf("%lld", ans);
}