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

int N;
pii s;
vector<pii> v;

int u, d, r, l;

int main(){
	scanf("%d", &N);
	scanf("%d%d", &s.first, &s.second);
	for(int i=0; i<N; i++){
		pii p; scanf("%d%d", &p.first, &p.second);
		if(p.first<s.first){
			u++;
		}if(p.first>s.first){
			d++;
		}if(p.second<s.second){
			l++;
		}if(p.second>s.second){
			r++;
		}
	}
	int mx = 0;
	mx = max(u, max(d, max(r, l)));
	printf("%d\n", mx);
	if(mx==u){
		printf("%d %d", s.first-1, s.second);
	}else if(mx==d){
		printf("%d %d", s.first+1, s.second);
	}else if(mx==r){
		printf("%d %d", s.first, s.second+1);
	}else{
		printf("%d %d", s.first, s.second-1);
	}
	return 0;
}