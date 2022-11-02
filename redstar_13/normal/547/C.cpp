#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 500010

int prime[NN];
VI res[NN];
int w[NN];
int p[NN];
int vst[NN];

int pre() {
	for(int i=2; i<NN; i++) if(!p[i]){
		for(int j=i; j<NN; j+=i) p[j] = i;
	}
	w[1] = 1;
	for(int i=2; i<NN; i++) {
		if(p[i] == i) prime[i] = 1;
		if(i/p[i] % p[i] == 0) continue;
		w[i] = w[i/p[i]] * -1;
	}
	for(int i=1; i<NN; i++) if(w[i] != 0) {
		for(int j=i; j<NN; j+=i) res[j].push_back(i);
	}
}

int lcm[NN];
int tot = 0;

int add(int u) {
	int s = 0;
	for(auto x : res[u]) {
		s += lcm[x] * w[x];
		lcm[x]++;
	}
	tot++;
	return s;
}

int sub(int u) {
	int s = 0;
	for(auto x : res[u]) {
		lcm[x]--;
		s += lcm[x] * w[x];
	}
	tot--;
	return s;
}

int A[NN], flag[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, Q;
	gn(n, Q);
	for(int i=1; i<=n; i++) gn(A[i]), vst[A[i]] = 1;
	pre();
	
	INT ans = 0;
	
	while(Q--) {
		int id; gn(id);
		if(flag[id]) {
			ans -= sub(A[id]);
			flag[id] ^= 1;
			printf("%I64d\n", ans);
			continue;
		}
		ans += add(A[id]);
		flag[id] ^= 1;
		printf("%I64d\n", ans);
	}
	
}