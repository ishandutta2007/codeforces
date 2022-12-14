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
const int MAX_N = 500;

int N, K;

vector<int> v;
bool chk[MAX_N+1], in[MAX_N+1];

pii ask(){
	printf("? ");
	for(int i=0; i<v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	fflush(stdout);
	pair<int, int> p;
	scanf("%d%d", &p.first, &p.second);
	return p;
}

pii mn={0, 0};

void rmv(int x){
	chk[x] = true;
	for(int i=0; i<v.size()-1; i++){
		if(v[i]==x){
			v[i] = v[v.size()-1];
			break;
		}
	}
	in[x] = false;
	v.pop_back();
	return;
}

void add(int x){
	v.pb(x);
	in[x] = true;
}

vector<int> vt;

int main(){
	scanf("%d%d", &N, &K);
	for(int i=1; i<=K; i++){
		v.pb(i);
		in[i] = true;
	}
	while(1){
		pii ret = ask();
		if(mn==(pii){0, 0} || mn.second>ret.second){
			mn = ret;
		}
		rmv(ret.first);
		bool b = false;
		for(int i=1; i<=N; i++){
			if(in[i]==false && chk[i]==false){
				b = true;
				add(i);
				break;
			}
		}
		if(b){
			continue;
		}else{
			add(mn.first);
			break;
		}
	}
	//ask();
	for(int i=0; i<v.size(); i++){
		vt.pb(v[i]);
	}
	int k;
	for(int i=1; i<=N; i++){
		if(in[i]==false){
			k = i;
			break;
		}
	}
	//cout<<k<<endl;
	add(k);
	int ans = 1;
	for(int i=0; i<vt.size(); i++){
		if(vt[i]==mn.first)	continue;
		rmv(vt[i]);
		pii p = ask();
		if(p.first!=mn.first){
			ans++;
		}
		add(vt[i]);
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}