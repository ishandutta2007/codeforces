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

int N, M, K;

string str;

vector<pair<int, string> > ans;

void add(int x){
	if(K==0)	return;
	if(x==0)	return;
	int k = str.size();
	if(k*x<=K){
		K-=k*x;
		ans.pb((pair<int, string>){x, str});
	}else{
		int t = K/k;
		if(t!=0)	ans.pb({t, str});
		K-=t*k;
		while(K<k){
			K++;
			str.pop_back();
		}
		if(str.size()!=0)	ans.pb({1, str});
		K = 0;
	}
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	if(4*N*M-2*N-2*M<K){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	str = "R"; add(M-1);
	str = "L"; add(M-1);
	for(int i=1; i<N; i++){
		str="D"; add(1);
		str="RUD"; add(M-1);
		str="L"; add(M-1);
	}
	str="U"; add(N-1);
	printf("%d\n", (int)ans.size());
	for(pair<int, string> i : ans){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}