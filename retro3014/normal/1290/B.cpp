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
const int MAX_N = 200000;
const int MAX_K = 30;

string str;
int N, Q;
int sum[MAX_K+1][MAX_N+1];

int main(){
	cin>>str;
	N = str.size();
	for(int i=1; i<=N; i++){
		for(int j=0; j<='z'-'a'; j++){
			sum[j][i]=sum[j][i-1];
		}
		sum[str[i-1]-'a'][i]++;
	}
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		int l, r; scanf("%d%d", &l, &r);
		if(l==r){
			printf("YES\n");
		}
		else if(str[l-1]!=str[r-1]){
			printf("YES\n");
		}else{
			int cnt = 0;
			for(int j=0; j<='z'-'a'; j++){
				if(sum[j][r]-sum[j][l-1]>0){
					cnt++;
				}
			}
			if(cnt>2){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}