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
const int MAX_M = 10000;
const int MAX_G = 1000;
const int MAX_K = 10000000;
int N, M;
int G, R;
vector<int> vt;

bool vst[MAX_K+1];

int tonum(int a, int b){
	return b+a*G;
}

vector<int> v1[MAX_G+1], v2[MAX_G+1];

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++){
		int x; scanf("%d", &x);
		vt.pb(x);
	}
	sort(vt.begin(), vt.end());
	scanf("%d%d", &G, &R);
	v1[0].pb(0);
	ll C = 0LL;
	while(1){
		for(int i=0; i<G; i++){
			while(!v1[i].empty()){
				int x = v1[i].back(), y = i;
				v1[i].pop_back();
				if(vst[tonum(x, y)])	continue;
				vst[tonum(x, y)] = true;
				//cout<<x<<" "<<y<<" "<<C<<endl;
				if(x==M-1){
					if(x!=0 && y==0){
						printf("%lld", (C-1LL)*(ll)(R+G)+(ll)G);
					}
					else	{
						printf("%lld", C*(ll)(R+G)+(ll)i);
					}
					return 0;
				}
				if(x!=0){
					int d = vt[x]-vt[x-1];
					if(d+y<G){
						if(!vst[tonum(x-1, y+d)]){
							v1[d+y].pb(x-1);
						}
					}else if(d+y==G){
						v2[0].pb(x-1);
					}
				}
				int d = vt[x+1]-vt[x];
				if(d+y<G){
					if(!vst[tonum(x+1, y+d)]){
						v1[d+y].pb(x+1);
					}
				}else if(d+y==G){
					v2[0].pb(x+1);
				}
			}
		}
		if(v2[0].empty()){
			break;
		}
		C++;
		while(!v2[0].empty()){
			v1[0].pb(v2[0].back());
			v2[0].pop_back();
		}
	}
	printf("-1");
	return 0;



	// while(!pq.empty()){
	// 	ll dist = pq.top().first;
	// 	int x = pq.top().second.first, y = pq.top().second.second; pq.pop();
	// 	if(vst[tonum(x, y)]){
	// 		continue;
	// 	}
	// 	vst[tonum(x, y)] = true;
	// 	//cout<<x<<" "<<y<<" "<<dist<<endl;
	// 	if(x==0 && y==0){
	// 		printf("%lld", dist);
	// 		return 0;
	// 	}
		
	// 	if(y==0){
	// 		if(x!=N-1){
	// 			dist+=(ll)R;
	// 		}
	// 		y=G;
	// 	}
	// 	if(x!=0){
	// 		int d = vt[x]-vt[x-1];
	// 		if(d<=y){
	// 			pq.push({dist+(ll)d, {x-1, y-d}});
	// 		}
	// 	}
	// 	if(x!=M-1){
	// 		int d = vt[x+1]-vt[x];
	// 		if(d<=y){
	// 			pq.push({dist+(ll)d, {x+1, y-d}});
	// 		}
	// 	}
	// }
	// printf("-1");
	return 0;
}