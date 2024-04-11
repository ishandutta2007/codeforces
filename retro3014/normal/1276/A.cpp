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
const int MAX_N = 1;
int T;
string str;
struct S{
	char c;
	int x, y;
};
vector<S> vt;
vector<int> ans;

int main(){
	scanf("%d", &T);
	while(T--){
		cin>>str;
		while(!ans.empty())	ans.pop_back();
		while(!vt.empty()) vt.pop_back();
		for(int i=0; i<str.size(); i++){
			if(vt.empty()){
				vt.pb({str[i], i, 1});
			}else{
				if(vt.back().c==str[i]){
					vt[vt.size()-1] = {vt.back().c, vt.back().x, vt.back().y+1};
				}else{
					vt.pb({str[i], i, 1});
				}
			}
		}
		for(int i=1; i<vt.size()-1; i++){
			if(vt[i].c=='w' && vt[i].y==1){
				if(i+2<vt.size()-1 && vt[i+2].c=='n' && vt[i+2].y==1){
					if(vt[i-1].c=='t' && vt[i+1].c=='o' && vt[i+3].c=='e'){
						if(vt[i+1].y==1){
							ans.pb(vt[i+1].x);
						}else{
							ans.pb(vt[i].x); ans.pb(vt[i+2].x);
						}
						i+=2;
					}else{
						if(vt[i-1].c=='t' && vt[i+1].c=='o'){
							ans.pb(vt[i].x);
						}
					}
				}else{
					if(vt[i-1].c=='t' && vt[i+1].c=='o'){
						ans.pb(vt[i].x);
					}
				}
			}else if(vt[i].c=='n' && vt[i].y==1){
				if(vt[i-1].c=='o' && vt[i+1].c=='e'){
					ans.pb(vt[i].x);
				}
			}
		}
		printf("%d\n", ans.size());
		for(int i=0; i<ans.size(); i++){
			printf("%d ", ans[i]+1);

		}
		printf("\n");
	}
	return 0;
}