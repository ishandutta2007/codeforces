#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 202020
#define pb push_back

int a[NN], cnt[222], flag[NN];
vector<int> vec;

inline void solve() {
	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%1d", a+i);
	for(int i=1; i<=n; i++) cnt[a[i]]++, flag[i]=0;
	
	int pos=0;
	for(int i=1; i<=n; i++) {
		while(cnt[pos]==0) pos++;
		if(a[i]==pos) cnt[pos]--, flag[i]=1;
		else flag[i]=2;
	}
	
	vec.clear();
	for(int i=1; i<=n; i++) if(flag[i]==1) vec.pb(a[i]);
	for(int i=1; i<=n; i++) if(flag[i]==2) vec.pb(a[i]);
	
	bool can=true;
	for(int i=1; i<vec.size(); i++) if(vec[i-1]>vec[i]) {
		can=false; break;
	}
	if(can) {
		for(int i=1; i<=n; i++) printf("%d", flag[i]); puts("");
	}
	else puts("-");
	for(int i=1; i<=n; i++) cnt[a[i]]=0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
}