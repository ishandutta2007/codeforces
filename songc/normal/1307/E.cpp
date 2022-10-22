#include <bits/stdc++.h>
#define pb push_back
#define MOD 1'000'000'007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, ans;
int A[5050];
LL ansc=1;
vector<pii> C[5050];

int main(){
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++) scanf("%d", &A[i]);
	for (int i=1; i<=M; i++){
		int c, h, a=0;
		pii p;
		scanf("%d %d", &c, &h);
		for (int i=1; i<=N; i++){
			if (A[i] == c){
				a++;
				if (a == h){
					p.first = i;
					break;
				}
			}
		}
		if (a < h) continue;
		a=0;
		for (int i=N; i>=1; i--){
			if (A[i] == c){
				a++;
				if (a == h){
					p.second = i;
					break;
				}
			}
		}
		C[c].pb(p);
	}

	for (int i=1; i<=N; i++){
		for (int j=0; j<C[i].size(); j++){
			int x=1;
			LL cnt=1;
			for (int k=1; k<=N; k++){
				LL l=0, r=0, lr=0;
				if (k == i){
					for (pii t : C[i]) if (t != C[i][j] && t.second > C[i][j].first) r++;
					if (r){
						x++;
						cnt = (cnt*r)%MOD;
					}
					continue;
				}
				for (pii t : C[k]){
					if (t.first < C[i][j].first && t.second > C[i][j].first) lr++;
					else if (t.first < C[i][j].first) l++;
					else if (t.second > C[i][j].first) r++;
				}
				if (l*r || l*lr || r*lr || lr>1){
					x += 2;
					cnt *= (l*r + l*lr + lr*r + lr*(lr-1));
					cnt %= MOD;
				}
				else if (l || r || lr){
					x++;
					cnt *= (l+r+2*lr);
					cnt %= MOD;
				}
			}
			if (x > ans){
				ans = x;
				ansc = 0;
			}
			if (x == ans) ansc = (ansc + cnt) % MOD;
		}
	}

	int x=0;
	LL cnt=1;
	for (int k=1; k<=N; k++){
		LL r=0;
		for (pii t : C[k]) r++;
		if (r){
			x++;
			cnt = (cnt*r)%MOD;
		}
	}
	if (x > ans){
		ans = x;
		ansc = 0;
	}
	if (x == ans) ansc = (ansc + cnt) % MOD;

	if (ans == 0) puts("0 1");
	else printf("%d %lld\n", ans, ansc);
	return 0;
}