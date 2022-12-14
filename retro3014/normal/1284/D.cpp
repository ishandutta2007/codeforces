#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
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
const int MAX_N = 500000;

int N;
struct S{
	int sa, ea, sb, eb;
};
vector<S> vt;
struct Query{
	int x, y1, y2;
	int type;
	bool operator <(const Query &a)const{
		if(x==a.x){
			if(type==1){
				if(a.type==1){
					if(y1==a.y1)	return y2<a.y2;
					return y1<a.y1;
				}
				return false;
			}else{
				if(a.type==1){
					return true;
				}
				if(y1==a.y1){
					return y2<a.y2;
				}return y1<a.y1;
			}
		}
		return x<a.x;
	}
};
vector<int> v;
map<int, int> mp;

vector<Query> query;


int g[MAX_N+1];
int nxt[MAX_N+1];
bool chk[MAX_N+1];

void ig(){
	int SZ = v.size();
	for(int i=1; i<=SZ; i++){
		g[i] = i;
		nxt[i] = i+1;
		chk[i] = false;
	}
}

int fg(int x){
	return (x==g[x])?x:g[x] = fg(g[x]);
}


bool solve(){
	ig();
	sort(query.begin(), query.end());
	for(int i=0; i<query.size(); i++){
		if(query[i].type==1){
			if(chk[fg(query[i].y1)] || chk[fg(query[i].y2)])	return true;			
		}else{	
			query[i].y1 = fg(query[i].y1);
			//cout<<endl<<query[i].y1<<" "<<query[i].y2<<endl;
			int t = nxt[query[i].y1];
			chk[query[i].y1] = true;
			while(t<=query[i].y2){
				//cout<<t<<" "<<nxt[t]<<endl;
				int tmp = nxt[t];
				g[t] = query[i].y1;
				chk[t] = true;
				t = tmp;
			}
			nxt[query[i].y1] = t;
		}
	}
	return false;
}


int main(){
	scanf("%d", &N);
	for(int i=0 ;i<N; i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		vt.pb({a, b, c, d});
		v.pb(a); v.pb(b); v.pb(c); v.pb(d);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		mp[v[i]] = i+1;
	}
	for(int i=0; i<N; i++){
		vt[i].sa = mp[vt[i].sa];
		vt[i].ea = mp[vt[i].ea];
		vt[i].sb = mp[vt[i].sb];
		vt[i].eb = mp[vt[i].eb];
	}
	for(int i=0; i<N; i++){
		query.pb({vt[i].sa-1, vt[i].sb, vt[i].eb, 1});
		query.pb({vt[i].ea, vt[i].sb, vt[i].eb, 2});
	}
	if(solve()){
		printf("NO\n");
		return 0;
	}
	while(!query.empty())	query.pop_back();
	for(int i=0; i<N; i++){
		query.pb({vt[i].sb-1, vt[i].sa, vt[i].ea, 1});
		query.pb({vt[i].eb, vt[i].sa, vt[i].ea, 2});
	}
	if(solve()){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}