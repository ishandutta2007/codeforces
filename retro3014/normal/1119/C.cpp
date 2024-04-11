#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 500;

int N, M;
int A[MAX_N+1][MAX_N+1], B[MAX_N+1][MAX_N+1];
int C[MAX_N+1][MAX_N+1];

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &A[i][j]);
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &B[i][j]);
			if(A[i][j]!=B[i][j]){
				C[i][j] = 1;
			}
		}
	}
	for(int i=1; i<=N; i++){
		int cnt=0;
		for(int j=1; j<=M; j++){
			if(C[i][j]==1 && i==N){
				printf("No");
				return 0;
			}else if(C[i][j]==1){
				cnt++;
				C[i+1][j] = 1-C[i+1][j];
			}
		}
		if(cnt%2==1){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}