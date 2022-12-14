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



vector<int> v;

string S, P;
int st[MAX_N+1];
int dp[MAX_N+1][MAX_N+1];
int D[MAX_N+1];
int s[MAX_N+1], e[MAX_N+1];

priority_queue<int> pq1, pq2;

vector<pii> vt;


int main(){
	cin>>S>>P;
	for(int i=0; i<S.size(); i++){
		int k = P.size()-1;
		st[i] = -1;
		for(int j=i; j>=0; j--){
			if(S[j]==P[k]){
				if(k==0){
					st[i] = j;
					break;
				}else{
					k--;
				}
			}
		}
		if(st[i]!=-1){
			if(st[i]==0)	D[i] = 1;
			else	D[i] = D[st[i]-1] + 1;
		}
		//.cout<<i<<" "<<st[i]<<endl;
	}
	for(int i=0; i<S.size(); i++){
		for(int j=1; j<S.size(); j++){
			dp[i][j] = INF;
		}
	}
	for(int i=0; i<S.size(); i++){
		for(int j=0; j<=D[i]; j++){
			if(i!=0)	dp[i][j] = dp[i-1][j];
		}
		if(D[i]!=0){
			if(st[i]==0){
				dp[i][D[i]] = min(dp[i][D[i]], (int)(i - st[i] + 1 - P.size()));
			}else{
				for(int j=1; j<=D[i]; j++){
					dp[i][j] = min(dp[i][j], dp[st[i]-1][j-1] + (int)(i - st[i] + 1 - P.size()));
				}
			}	
			
		}
		//cout<<i<<endl;
		//for(int j=0; j<=D[i]; j++){
		//	cout<<dp[i][j]<<" ";
		//}
	}
	for(int i=0; i<=D[S.size()-1]; i++){
		//cout<<dp[S.size()-1][i]<<" ";
		s[i] = dp[S.size()-1][i];
		e[i] = S.size() - P.size() * i;
		vt.pb({s[i], i});
		vt.pb({e[i]+1, -i-1});
	}
	sort(vt.begin(), vt.end());
	int idx = 0;
	for(int i=0; i<=S.size(); i++){
		while(idx<vt.size() && vt[idx].first==i){
			if(vt[idx].second>=0){
				pq1.push(vt[idx].second);
			}else{
				pq2.push(-vt[idx].second-1);
			}
			//cout<<vt[idx].second<<endl;
			idx++;
		}
		while(!pq1.empty() && !pq2.empty() && pq1.top()==pq2.top()){
			//cout<<(pq1.empty()?-1:pq1.top())<<" "<<(pq2.empty()?-1:pq2.top())<<endl;
			pq1.pop();
			pq2.pop();
		}
		printf("%d ", pq1.top());
	}
	return 0;
}