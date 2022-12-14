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
const int MAX_N = 50;

int T;
int N, M;
int arr[MAX_N+1][MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				scanf("%d", &arr[i][j]);
			}
		}
		int c1 = 0, c2 = 0;
		for(int i=1; i<=N; i++){
			bool b = true;
			for(int j=1; j<=M; j++)	{
				if(arr[i][j]==1)	b = false;
			}
			c1+=(int)b;
		}
		for(int i=1; i<=M; i++){
			bool b = true;
			for(int j=1; j<=N; j++)	{
				if(arr[j][i]==1)	b = false;
			}
			c2+=(int)b;
		}
		c1 = min(c1, c2);
		//cout<<c1<<endl;
		if(c1%2){
			printf("Ashish\n");
		}else{
			printf("Vivek\n");
		}
	}
	return 0;
}