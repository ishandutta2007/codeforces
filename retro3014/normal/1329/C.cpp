#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 2000000;

int T;
int H, G, N, M;
vector<int> v;
vector<int> ans;
bool chk[MAX_N+1];
priority_queue<int, vector<int>, greater<int> > pq1, pq2; 


void rmv(int x){
	if(chk[x])	pq2.push(x);
	chk[x] = false;
	if(x*2>=N){
		v[x] = 0;
		return;
	}else{
		int l = x*2, r = x*2+1;
		if(v[l]==0 && v[r]==0){
			v[x] = 0;
			chk[x] = false;
		}else if(v[l]>v[r]){
			v[x] = v[l];
			rmv(l);
		}else{
			v[x] = v[r];
			rmv(r);
		}
		if(v[l] == 0 && v[r]==0){
			if(x>=M){
				pq1.push(x);
				chk[x] = true;
			}
		}else if(v[l]>v[r]){
			if(chk[l]){
				pq1.push(x);
				chk[x] = true;
			}
		}else{
			if(chk[r]){
				pq1.push(x);
				chk[x] = true;
			}
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &H, &G);
		N = (1<<H);
		M = (1<<G);
		while(!v.empty())	v.pop_back();
		while(!ans.empty())	ans.pop_back();
		v.pb(0);
		for(int i=1; i<N; i++){
			chk[i] = true;
			int a; scanf("%d", &a);
			v.pb(a);
		}
		int now, l, r;
		for(int i=1; i<N; i++){
			while(chk[i]){
				ans.pb(i);
				now = i;
				while(1){
					chk[now] = false;
					if(now*2>=N){
						v[now] = 0;
						break;
					}else{
						l = now*2;
						r = now*2+1;
						if(v[l]==0 && v[r]==0){
							v[now] = 0;
							break;
						}else if(v[l]>v[r]){
							v[now] = v[l];
							now = l;
						}else{
							v[now] = v[r];
							now = r;
						}
					}
				}
				chk[now] = false;
				now/=2;
				while(now>=i){
					l = now*2;
					r = now*2+1;
					if(v[l]==0 && v[r]==0){
						if(now>=M){
							chk[now] = true;
						}
					}else if(v[l]>v[r]){
						chk[now] = chk[l];
					}else{
						chk[now] = chk[r];
					}
					now/=2;
				}
			}
		}
		ll sum = 0;
		for(int i=1; i<M; i++){
			sum+=(ll)v[i];
		}
		printf("%lld\n", sum);
		for(int i=0; i<ans.size(); i++){
			printf("%d ", ans[i]);
		}printf("\n");
	}
	return 0;
}