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
const ll INFLL = 1e18;
const int MAX_N = 1;
const int INF = 100000;
 
int T;
int N, X;
string str;
int cnt[INF*2+1];
 
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &X);
		cin>>str;
		int sum = 0;
		for(int j=0; j<str.size(); j++){
			cnt[sum+INF]++;
			if(str[j]=='0'){
				sum++;
			}else{
				sum--;
			}
		}
		int ans = 0;
		if(sum==0){
			if(X+INF<=INF*2 && X+INF>=0 && cnt[X+INF]!=0){
				printf("-1\n");
			}else{
				printf("0\n");
			}
		}else{
			if(sum<0){
				sum *= -1;
				X = max(X+INF, ((X+INF)%sum + sum) % sum);
				while(X<=INF*2){
					ans+=cnt[X];
					X+=sum;
				}
			}else{
				int T = X;
				X = min(((X+INF)%sum + sum) % sum, (T+INF));
				while(X<=min(INF*2, T+INF) && X>=0){
					ans+=cnt[X];
					X+=sum;
				}
			}
			printf("%d\n", ans);
		}
		sum = 0;
		for(int j=0; j<str.size(); j++){
			cnt[sum+INF]=0;
			if(str[j]=='0'){
				sum++;
			}else{
				sum--;
			}
		}
	}
	return 0;
}