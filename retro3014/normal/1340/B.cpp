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
const int MAX_N = 2000;

int N, K;
string str;

int num[10];
int arr[MAX_N+1];

int tonum(){
	int ret = 0;
	for(int i=0; i<7; i++){
		ret*=2LL;
		ret+=(int)(str[i]-'0');
	}
	return ret;
}
bool chk[MAX_N+1][MAX_N+1];

void input(){
	scanf("%d%d", &N, &K);
	str = "1110111"; num[0] = tonum();
	str = "0010010"; num[1] = tonum();
	str = "1011101"; num[2] = tonum();
	str = "1011011"; num[3] = tonum();
	str = "0111010"; num[4] = tonum();
	str = "1101011"; num[5] = tonum();
	str = "1101111"; num[6] = tonum();
	str = "1010010"; num[7] = tonum();
	str = "1111111"; num[8] = tonum();
	str = "1111011"; num[9] = tonum();
	for(int i=1; i<=N; i++){
		cin>>str;
		arr[i] = tonum();
	}
}

int cnt(int x){
	int ret = 0;
	while(x>0){
		ret+=x%2;
		x/=2;
	}
	return ret;
}

int main(){
	input();
	for(int i=0; i<10; i++){
		if((arr[N] & num[i])==arr[N]){
			chk[N][cnt(num[i]-arr[N])] = true;
		}
	}
	for(int i=N-1; i>=0; i--){
		for(int n=0; n<10; n++){
			if((arr[i] & num[n])==arr[i]){
				int t = cnt(num[n]-arr[i]);
				for(int j=0; j<=K; j++){
					if(j>=t && chk[i+1][j-t]){
						chk[i][j] = true;
					}
				}	
			}
		}
	}	
	if(!chk[1][K]){
		printf("-1");
		return 0;
	}
	int k = K;
	for(int i=1; i<=N; i++){
		for(int n=9; n>=0; n--){
			if((arr[i] & num[n])==arr[i]){
				int t = cnt(num[n]-arr[i]);
				if(i==N){
					if(t==k){
						printf("%d", n);
						break;
					}
				}else{
					if(chk[i+1][k-t]){
						printf("%d", n);
						k-=t;
						break;
					}
				}
			}
		}
	}

	return 0;
}