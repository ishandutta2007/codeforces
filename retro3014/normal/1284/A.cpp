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
const int MAX_N = 20;

int N, M, Q;
string str1[MAX_N+1], str2[MAX_N+1];

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++){
		cin>>str1[i];
	}
	for(int j=0; j<M; j++){
		cin>>str2[j];
	}
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		int y; scanf("%d", &y);
		y--;
		cout<<str1[y%N]<<str2[y%M]<<endl;
	}
	return 0;
}