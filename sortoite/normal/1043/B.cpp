#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

int n;

#define NN 1010

int a[NN];

inline bool can(int N) {
	for(int i=N; i<n; i++) if(a[i]!=a[i%N]) return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	for(int i=n; i>=1; i--) a[i]=a[i]-a[i-1];
	for(int i=0; i<n; i++) a[i]=a[i+1];
	
	vector<int> ans;
	for(int i=1; i<=n; i++) if(can(i)) ans.pb(i);
	printf("%d\n", ans.size());
	for(int x: ans) printf("%d ", x);
}