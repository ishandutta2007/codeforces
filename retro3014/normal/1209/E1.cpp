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
const int MAX_N = 200;

int T;
int N, M;
struct S{
	int data;
	int x, y;
	bool operator <(const S &a)const{
		return data<a.data;
	}
};
vector<S> v, vt;
vector<int> cnt[MAX_N+1];

int zero(int x){
	return (x>0)?(x):(-x);
}

int main(){
	cin>>T;
	while(T--){
		while(!v.empty())	v.pop_back();
		for(int i=0; i<vt.size(); i++){
			while(!cnt[vt[i].y].empty()){
				cnt[vt[i].y].pop_back();
			}
		}
		while(!vt.empty()) vt.pop_back();
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				int x; scanf("%d", &x);
				v.pb({x, i, j});
			}
		}
		sort(v.begin(), v.end());
		if(N<=3){
			int ans = 0;
			while(N--){
				ans += v.back().data;
				v.pop_back();
			}
			printf("%d\n", ans);
		}else{
			int ans = 0;
			int chk = 0;
			int y1 = 0, y2 = 0;
			for(int i=0; i<N; i++){
				ans += v.back().data;
				vt.pb(v.back());
				cnt[v.back().y].pb(v.back().x);
				if(cnt[v.back().y].size()==1){
					chk++;
					if(y1==0){
						y1 = v.back().y;
					}else{
						y2 = v.back().y;
					}
				}
				v.pop_back();
			}
			if(chk!=2){
				printf("%d\n", ans);
			}else{
				if(cnt[y1].size()!=2){
					printf("%d\n", ans);
				}else{
					//cout<<"*";
					int x1, x2, x3, x4;
					x1 = min(cnt[y1][0], cnt[y1][1]);
					x2 = max(cnt[y1][0], cnt[y1][1]);
					x3 = min(cnt[y2][0], cnt[y2][1]);
					x4 = max(cnt[y2][0], cnt[y2][1]);
					if(((x2-x1==2) && (x4-x3==1 || x4-x3==3))){
						if(v.back().y==vt.back().y && zero(v.back().x - vt.back().x)==2){
							S n = v.back(); v.pop_back();
							ans = max(ans - vt[2].data + n.data, ans - vt.back().data + v.back().data);
							printf("%d\n", ans);
						}else{
							ans -= vt.back().data;
							ans += v.back().data;
							printf("%d\n", ans);	
						}
					}else if(((x2-x1==1||x2-x1==3)&&(x4-x3==2))){
						if(v.back().y==vt.back().y&& zero(v.back().x - vt.back().x)==2){
							S n = v.back(); v.pop_back();
							ans = max(ans - vt[2].data + n.data, ans - vt.back().data + v.back().data);
							printf("%d\n", ans);
						}else{
							ans -= vt.back().data;
							ans += v.back().data;
							printf("%d\n", ans);	
						}
					}else{
						printf("%d\n", ans);
					}
				}
			}

		}
	}
	return 0;
}