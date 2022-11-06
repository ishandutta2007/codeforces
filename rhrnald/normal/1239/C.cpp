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

vector<pii> v;
priority_queue<int, vector<int>, greater<int>> Q;
queue<int> q;
ll ans[N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		int t;
		scanf("%d", &t);
		v.push_back({t,i});
	}
	sort(all(v));

	ll cur=-1;
	int idx=0;
	int cnt=0;
	while(cnt<n) {
		if(q.empty() && Q.empty()) cur=v[idx].first;
		
		while(idx<n && v[idx].first<=cur+m) {
			if(q.empty() || q.back()>v[idx].second) q.push(v[idx++].second);
			else Q.push(v[idx++].second);
		}
		
		cur+=m;
		ans[q.front()]=cur; q.pop();
		cnt++;

		if(q.empty() && !Q.empty()) {
			q.push(Q.top()); Q.pop();
		}
	}
	for(int i=0; i<n; i++) printf("%lld ", ans[i]);
}