#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 606060

int n;
INT val[NN], mask[NN], sum, ans;
vector<INT> res[77];

inline int sgn(INT x) {
	return (x>0)-(x<0);
}

inline void check() {
	INT s=0;
	for(int i=1; i<=n; i++) {
		if(__builtin_popcountll(ans&mask[i])&1) s-=val[i];
		else s+=val[i];
	}
	if(sgn(sum)*sgn(s)==-1) cerr<<"Accepted"<<endl;
	else {
		cerr<<"Wrong Answer"<<endl;
		freopen("in.in", "w", stdout);
		cout<<n<<endl;
		for(int i=1; i<=n; i++) printf("%I64d %I64d\n", val[i], mask[i]);
		exit(0);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%I64d %I64d", val+i, mask+i);
		sum+=val[i];
	}
	if(sum<0) {
		sum=-sum;
		for(int i=1; i<=n; i++) val[i]=-val[i];
	}
	
	for(int i=1; i<=n; i++) {
		res[63-__builtin_clzll(mask[i])].pb(i);
	}
	for(int i=0; i<62; i++) {
		INT sum_odd=0, sum_even=0;
		for(auto x: res[i]) {
			if(__builtin_popcountll(mask[x] & ans) &1) sum_odd+=val[x];
			else sum_even+=val[x];
		}
		if(sum_even>sum_odd) ans^=1LL<<i;
	}
	printf("%I64d\n", ans);
}