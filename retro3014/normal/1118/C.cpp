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

const int MAX_K = 1000;
const int MAX_N = 20;

int N;
int cnt[MAX_K+1];
vector<int> vt4, vt2, vt1;
int arr[MAX_N+1][MAX_N+1];

int main(){
	scanf("%d", &N);
	for(int i=0; i<N*N; i++){
		int x;
		scanf("%d", &x); cnt[x]++;
	}
	for(int i=1; i<=MAX_K; i++){
		while(cnt[i]>=4){
			cnt[i]-=4; vt4.push_back(i);
		}
		if(cnt[i]>=2){
			cnt[i]-=2; vt2.push_back(i);
		}
		if(cnt[i]>=1){
			cnt[i]-=1; vt1.push_back(i);
		}
	}
	if(N%2==1){
		if(vt1.size()!=1){
			printf("NO"); return 0;
		}
		while(vt2.size()<N-1){
			vt2.push_back(vt4.back()); 
			vt2.push_back(vt4.back()); vt4.pop_back();
		}
		if(vt2.size()>N){
			printf("NO"); return 0;
		}
		printf("YES\n");
		int idx = 0;
		for(int i=0; i<N/2; i++){
			for(int j=0; j<N/2; j++){
				arr[i][j] = arr[N-i-1][j] = arr[N-i-1][N-j-1] = arr[i][N-j-1] = vt4[idx++];
			}
		}
		idx = 0;
		for(int i=0; i<N/2; i++){
			arr[i][N/2] = arr[N-i-1][N/2] = vt2[idx++];
		}
		for(int i=0; i<N/2; i++){
			arr[N/2][i] = arr[N/2][N-i-1] = vt2[idx++];
		}
		arr[N/2][N/2] = vt1.back();
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				printf("%d ", arr[i][j]);
			}printf("\n");
		}
	}else{
		if(!vt2.empty() || !vt1.empty()){
			printf("NO"); return 0;
		}printf("YES\n");
		int idx = 0;
		for(int i=0; i<N/2; i++){
			for(int j=0; j<N/2; j++){
				arr[i][j] = arr[N-i-1][j] = arr[N-i-1][N-j-1] = arr[i][N-j-1] = vt4[idx++];
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				printf("%d ", arr[i][j]);
			}printf("\n");
		}
	}
	return 0;
}