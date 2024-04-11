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
string str;

int main(){
	cin>>N>>str;
	int cnt = 0;
	int idx = -1;
	int sum = 0;
	for(int i=0; i<N; i++){
		if(str[i]=='('){
			cnt++;
			if(cnt==0){
				sum+=(i-idx+1);
			}
		}else{
			cnt--;
			if(cnt==-1){
				idx = i;
			}
		}
	}
	if(cnt==0){
		printf("%d", sum);
	}else{
		printf("-1");
	}
	return 0;
}