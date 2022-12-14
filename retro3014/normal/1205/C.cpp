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

int N;
int arr[MAX_N+1][MAX_N+1];
int ch = 0;
int fin = 0;
vector<pii> vt;

int ask(int x, int y, int z, int w){
	printf("? %d %d %d %d\n", x, y, z, w);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main(){
	scanf("%d", &N);
	arr[1][1] = 1;
	arr[N][N] = 0;
	arr[2][3] = 0;
	int k = ask(2, 1, 2, 3);
	arr[2][1] = 1-k;
	k = ask(1, 2, 2, 3);
	arr[1][2] = 1-k;
	k = ask(1, 1, 2, 2);
	arr[2][2] = k;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(i<=2 && j<=2)	continue;
			if(i==2 && j==3)	continue;
			if(i<=2){
				k = ask(i, j-2, i, j);
				arr[i][j] = (arr[i][j-2]+k+1)%2;
			}else{
				k = ask(i-2, j, i, j);
				arr[i][j] = (arr[i-2][j]+k+1)%2;
			}
		}
	}
	for(int i=1; i<=N-1; i++){
		for(int j=2; j<=N; j++){
			if(arr[i][j]!=arr[i+1][j-1]){
				if(i+2<=N){
					k = ask(i, j-1, i+2, j);
					if(((arr[i][j-1]==arr[i+2][j])^k)){
						ch = 1;
					}
					fin = 1;
					break;
				}else{
					k = ask(i-1, j-1, i+1, j);
					if(((arr[i-1][j-1]==arr[i+1][j])^k)){
						ch = 1;
					}
					fin = 1;
					break;
				}
			}
		}
		if(fin){
			break;
		}
	}
	if(!fin){
		int i = 1, j = 1;
		int n = -1;
		while(1){
			vt.pb({i, j});
			n++;
			if(i+j>=5){
				if((arr[vt[n].first][vt[n].second]==arr[vt[n-2].first][vt[n-2].second]) == (arr[vt[n-1].first][vt[n-1].second]==arr[vt[n-3].first][vt[n-3].second])){
					int k = ask(vt[n-3].first, vt[n-3].second, vt[n].first, vt[n].second);
					if((arr[vt[n].first][vt[n].second]==arr[vt[n-3].first][vt[n-3].second])^k){
						ch = 1;
					}
					break;
				}
			}
			if(j==N)	i++;
			else	j++;
		}
	}	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if((i+j)%2==0)	continue;
			arr[i][j] = (arr[i][j]+ch)%2;
		}
	}
	printf("!\n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++)	printf("%d", arr[i][j]);
		printf("\n");
	}
	fflush(stdout);
	return 0;
}