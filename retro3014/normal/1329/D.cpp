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
const int MAX_K = 30;

int T;
string str;
int N;
vector<pii> vt;

priority_queue<pii> pq;
bool chk[MAX_N+1];
int cnt[MAX_K+1];

vector<pii> gp1[MAX_K+1], gp2[MAX_K+1];
vector<pii> ans;

int tree[MAX_N+1];

void Add(int x, int y){
	while(x<=N){
		tree[x]+=y;
		x += (x & -x);
	}
}

int Sum(int x){
	int ret = 0;
	while(x>0){
		ret+=tree[x];
		x -= (x & -x);
	}
	return ret;
}

int prv[MAX_N+1], nxt[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		cin>>str;
		N = (int)str.size();
		while(!ans.empty())	ans.pop_back();
		while(!vt.empty())	vt.pop_back();
		for(int i=0; i<(int)str.size()-1; i++){
			if(str[i]==str[i+1]){
				vt.pb({str[i]-'a', i});
			}
		}
		while(!pq.empty())	pq.pop();
		for(int i=0; i<MAX_K; i++){
			cnt[i] = false;
			while(!gp1[i].empty())	gp1[i].pop_back();
			while(!gp2[i].empty())	gp2[i].pop_back();
		}
		for(int i=0; i<vt.size(); i++){
			prv[i] = i-1;
			nxt[i] = i+1;
		}
		for(int i=0; i<(int)vt.size()-1; i++){
			if(vt[i].first==vt[i+1].first){
				gp2[vt[i].first].pb({i, i+1});
			}else{
				gp1[vt[i].first].pb({i, i+1});
				gp1[vt[i+1].first].pb({i, i+1});
			}
		}
		for(int i=0; i<(int)vt.size(); i++){
			chk[i] = false;
			cnt[vt[i].first]++;
		}
		for(int i=0; i<MAX_K; i++){
			if(cnt[i]!=0){
				pq.push({cnt[i], i});
			}
		}
		bool tf2 = false;
		while(!pq.empty()){
			pii p = pq.top();
			int now = pq.top().second; pq.pop();
			if(cnt[now]!=p.first)	continue;
			bool tf = false;
			while(!gp1[now].empty()){
				pii n = gp1[now].back(); gp1[now].pop_back();
				if(!chk[n.first] && !chk[n.second]){
					ans.pb({n.first, n.second});
					chk[n.first] = true;
					chk[n.second] = true;
					cnt[vt[n.first].first]--;
					cnt[vt[n.second].first]--;
					pq.push({cnt[vt[n.first].first], vt[n.first].first});
					pq.push({cnt[vt[n.second].first], vt[n.second].first});
					if(prv[n.first]==-1){
						if(nxt[n.second]==(int)vt.size()){
							continue;
						}else{
							prv[nxt[n.second]] = -1;
						}
					}else{
						if(nxt[n.second]==(int)vt.size()){
							nxt[prv[n.first]] = (int)vt.size();
						}else{
							prv[nxt[n.second]] = prv[n.first];
							nxt[prv[n.first]] = nxt[n.second];
							int i1 = prv[n.first], i2 = nxt[n.second];
							prv[i2] = i1;	nxt[i1] = i2;
							if(vt[i1].first!=vt[i2].first){
								gp1[vt[i1].first].pb({i1, i2});
								gp1[vt[i2].first].pb({i1, i2});
							}
						}
					}
					tf = true;
					break;
				}
			}
			if(tf)	continue;
			int prv = -1;
			for(int i=0; i<vt.size(); i++){
				if(chk[i]==false){
					ans.pb({prv, i});
					prv = i;
				}
			}
			ans.pb({prv, vt.size()});
			tf2 =true;
			break;
		}
		if(!tf2){
			ans.pb({-1, vt.size()});
		}
		for(int i=1; i<=N; i++){
			tree[i] = 0;
		}
		for(int i=1; i<=N; i++){
			Add(i, 1);
		}
		printf("%d\n", (int)ans.size());
		for(int i=0; i<ans.size(); i++){
			int l, r;
			if(ans[i].first==-1){
				l = 1;
			}else{
				l = vt[ans[i].first].second+2;
			}
			if(ans[i].second==vt.size()){
				r = N;
			}else{
				r = vt[ans[i].second].second+1;
			}
			int cl = Sum(l), cr = Sum(r);
			printf("%d %d\n", cl, cr);
			Add(r, cl-cr-1);
		}
	}
	return 0;
}