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
const int MAX_N = 100;
const int MAX_K = 2000;
 
int N, M;
bool b[MAX_N+10];
bool dp[MAX_N+10][MAX_K+10];
int from[MAX_N+10][MAX_K+10];
int mx = 0;
vector<int> v;
vector<int> vt;
int d[MAX_N+10];
int gp[MAX_N+10][MAX_N+10];
priority_queue<pii> pq;
vector<pii> arr;
 
int main(){
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		int a; scanf("%d", &a); b[a] = true;
		v.pb(a);	mx = max(mx, a);
	}
	if(M==1 && v.back()==0){
		printf("1\n0");
		return 0;
	}
	sort(v.begin(), v.end());
	dp[0][0] = 1;
	int sum = 0;
	int t = 0;
	for(int i=0; i<=MAX_N; i++){
		if(!b[i])	{
			sum += i;
			for(int k : v){
				for(int j=0; j+k<MAX_K; j++){
					if(dp[t][j] && j-from[t][j]<=k && !dp[t+1][j+k]){
						dp[t+1][j+k] = true;
						from[t+1][j+k] = j;
					}
				}
			}
			t++;
			for(int j=0; j<min(sum, MAX_K); j++){
				dp[t][j] = false;
			}
		}
		if(i<mx)	continue;
		if(dp[t][sum]){
			N = i;
			//cout<<i<<endl;
			i = t;
			while(i!=0){
				vt.pb(sum - from[i][sum]);
				sum = from[i--][sum]; 
			}
			sort(vt.begin(), vt.end());
			int idx = 0;
			for(int j=0; j<=N; j++){
				if(b[j]){
					d[j] = j;
				}else{
					d[j] = vt[idx++];
				}
				arr.pb({d[j], j});
			}
			/*for(int j=0; j<=N; j++){
				for(int k=j+1; k<=N; k++){
					gp[k][j] = true;
					d[k]--;
				}
			}
			for(int j=0; j<=N; j++){
				if(d[j]<0){					pq.push({-d[j], j});
				}
			}
			for(int j=0; j<=N; j++){
				while(d[j]>0){
					pii now = pq.top(); pq.pop();
					cout<<j<<" "<<now.second<<endl;
					d[j]--;
					gp[now.second][j] = false;
					gp[j][now.second] = true;
					if(now.first!=1)	arr.pb({now.first-1, now.second});
				}
				while(!arr.empty()){
					pq.push(arr.back()); arr.pop_back();
				}
			}*/
			while(!arr.empty()){
				sort(arr.begin(), arr.end());
				pii p = arr.back(); arr.pop_back();
				for(int j=0; j<p.first; j++){
					gp[p.second][arr[j].second] = true;
				}for(int j=p.first; j<arr.size(); j++){
					gp[arr[j].second][p.second] = true;
					arr[j].first--;
				}
			}
			printf("%d\n", N+1);
			for(int j=0; j<=N; j++){
				int sum = 0;
				for(int k=0; k<=N; k++){
					printf("%d", gp[j][k]);
					sum += gp[j][k];
				}
				//cout<<" "<<sum<<" "<<d[j];
				printf("\n");
			}
			return 0;
		}
	}
	printf("=(");
	return 0;
}