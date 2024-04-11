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
int n,m,L,x;
vector<pii> a, b, na, nb;
int ans[N];
ll sum[N];
ll delta[N];
int main(void){
	scanf("%d%d", &L, &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		a.push_back({x, i});
	}
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		b.push_back({x,i});
	}
	sort(all(a)); sort(all(b));
 
	for(int i=0; i<n; i++) {
		pii t={a[i].first, INF};
		int id1=lower_bound(all(b), t)-b.begin(); id1-=i; if(id1<0) id1+=n;
		delta[id1]-=a[i].first+a[i].first;
 
		t={a[i].first+L/2, INF}; if(t.first>L) t.first-=L;
		int id2=lower_bound(all(b), t)-b.begin(); id2-=i; if(id2<0) id2+=n;
		delta[id2]+=a[i].first+a[i].first;
		if(a[i].first<=L/2) {
			delta[id2]+=L;
			delta[n-i]-=L;
		} else {
			delta[id2]-=L;
			delta[n-i]+=L;
		}
		int l=abs(a[i].first-b[i].first);
		l=min(l, L-l);
		sum[0]+=l;
	}
	for(int i=0; i<n; i++) {
		pii t={b[i].first, -1};
		int id1=lower_bound(all(a), t)-a.begin(); id1--; if(id1<0) id1=n-1; id1=i-id1; if(id1<0) id1+=n;
		delta[id1]+=b[i].first+b[i].first;
		t={b[i].first+L/2, -1}; if(t.first>L) t.first-=L;
		int id2=lower_bound(all(a), t)-a.begin(); id2--; if(id2<0) id2=n-1; id2=i-id2; if(id2<0) id2+=n;
		delta[id2]-=b[i].first+b[i].first;
 
	}
	for(int i=1; i<n; i++) sum[i]=sum[i-1]+delta[i];
	ll mm=LINF;
	int idx=0;
	for(int i=0; i<n; i++) {
		if(mm>sum[i]) mm=sum[i], idx=i;
	}
	ll T=0;
	for(int i=0; i<n; i++) {
		ans[a[i].second]=b[(i+idx)%n].second;
		ll l=abs(a[i].first-b[(i+idx)%n].first);
	    T+=min(l, L-l);
	}
	printf("%lld\n", T);
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}