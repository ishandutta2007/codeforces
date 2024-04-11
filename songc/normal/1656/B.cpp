#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, K;
set<int> S;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &K);
		bool tf = false;
		int x;
		for (int i=1; i<=N; i++){
			scanf("%d", &x);
			if (S.find(K+x) != S.end()) tf = true;
			if (S.find(x-K) != S.end()) tf = true;
			S.insert(x);
		}
		S.clear();
		puts(tf?"YES":"NO");
	}
	return 0;
}