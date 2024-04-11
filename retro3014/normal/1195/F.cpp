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
const int MAX_N = 300000;

int N, Q, SQN;
struct S{
	int x, y, idx;
	bool operator < (const S &a)const{
		if(x==a.x){
			if(y==a.y){
				return idx<a.idx;
			}
			return y<a.y;
		}
		return x<a.x;
	}
};

vector<S> vt;
vector<pii> v;

int s[MAX_N+1], e[MAX_N+1];

int gcd(int x, int y){
	if(x<0)	x = -x;
	if(y<0)	y = -y;
	if(x==0)	return y;
	if(y==0)	return x;
	return gcd(y, x%y);
}

struct Query{
	int x, y, idx;
	bool operator <(const Query &a)const{
		if(x/SQN==a.x/SQN)	return y<a.y;
		return x<a.x;
	}
};
vector<Query> query;

int ans[MAX_N+1];
int chk[MAX_N+1];
int num[MAX_N+1];

int cnt = 0;



void add(int x){
	if(chk[num[x]]==0){
		cnt++;
	}
	chk[num[x]]++;
}

void rmv(int x){
	chk[num[x]]--;
	if(chk[num[x]]==0){
		cnt--;
	}
}

int main(){
	scanf("%d", &N);
	vt.pb({-INF, -INF, -INF});
	for(int i=1; i<=N; i++){
		int k, a, b; scanf("%d", &k);
		while(!v.empty())	v.pop_back();
		s[i] = vt.size();
		while(k--){
			scanf("%d%d", &a, &b);
			v.pb({a, b});
		}
		for(int j=0; j<v.size(); j++){
			pii p = {v[(j+1)%v.size()].first - v[j].first, v[(j+1)%v.size()].second - v[j].second};
			int g = gcd(p.first, p.second);
			p.first/=g; p.second/=g;
			vt.pb({p.first, p.second, (int)vt.size()});
		}
		e[i] = vt.size()-1;
	}
	sort(vt.begin(), vt.end());
	int c = 0;
	for(int i=1; i<vt.size(); i++){
		if(vt[i].x==vt[i-1].x && vt[i].y==vt[i-1].y){
			num[vt[i].idx] = c;
		}else{
			num[vt[i].idx] = ++c;
		}
	}
	SQN = sqrt((int)vt.size()-1);
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		int a, b; scanf("%d%d", &a, &b);
		query.pb({s[a], e[b], i});
	}
	sort(query.begin(), query.end());
	int x = 1, y = 0;
	for(Query now : query){
		while(now.x<x){
			add(x-1); x--;
		}
		while(now.y>y){
			add(y+1);	y++;
		}
		while(now.x>x){
			rmv(x); x++;
		}
		while(now.y<y){
			rmv(y); y--;
		}
		ans[now.idx] = cnt; 
	}
	for(int i=1; i<=Q; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}