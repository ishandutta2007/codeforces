#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007;
const ll INFLL = 1e18;
const int INF = 1e9;
const int MAX_N = 1000000;

int N;
int K;

vector<int> v1, v2, v;

bool chk[2][MAX_N+1];
int num[MAX_N+1];
int ans;

int main(){
	scanf("%d%d", &N, &K);
	if(K!=0)	ans++;
	for(int i=1; i<=K; i++){
		int x; scanf("%d", &x);
		chk[1][(1<<N)+x-1] = true;
	}
	for(int i=(1<<N); i<(1<<(N+1)); i+=2){
		if(chk[1][i] && chk[1][i+1]){
			int n = i/4;
			while(n>0){
				chk[0][n] = true;
				n/=2;
			}
		}
		if(chk[1][i] || chk[1][i+1]){
			chk[1][i/2] = true;
			ans++;
		}
	}
	int cnt=0;
	for(int i=(1<<(N-2)); i>0; i=i/2){
		for(int j=i; j<i*2; j++){
			if(chk[1][j*2] && chk[1][j*2+1]){
				if(!chk[0][j]){
					int n = j;
					int s = cnt;
					while(n>0){
						if(chk[0][n])	break;
						s++;
						n/=2;
					}
					if(s>cnt*2){
						ans-=cnt*2;
						n = j*(1<<cnt);
						while(n>0){
							chk[0][n] = true;
							n/=2;
						}
					}
				}
				chk[1][j] = true;
				ans+=2;
			}else if(chk[1][j*2] || chk[1][j*2+1]){
				chk[1][j] = true;
				ans+=2;
			}
		}
		cnt++;
	}
	for(int i=1; i<(1<<N); i++){
		//cout<<i<<" "<<chk[0][i]<<endl;
		ans+=(int)chk[0][i];
	}
	printf("%d", ans);
	return 0;
}