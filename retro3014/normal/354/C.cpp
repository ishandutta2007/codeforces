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

const int MAX_K = 1000000;

int N, K;

vector<int> v;
int sum[MAX_K+10];

int cnt[MAX_K+10];


int main(){
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		v.pb(x);
		int y = max(1, x-K);
		sum[y]++; sum[x+1]--;
		if(x-K>=1)	{cnt[1]++; cnt[K+1]--;}
		else	{cnt[1]++; cnt[x+1]--;}
	}
	for(int i=1; i<=MAX_K; i++){
		sum[i]+=sum[i-1];
	}
	int ans=1;
	for(int i=2; i<=K+1; i++){
		cnt[i] += cnt[i-1];
		if(cnt[i]==N){
			ans = i;
		}
	}
	for(int i=K+1; i<=MAX_K; i++){
		int sum2 = 0;
		for(int j=i; j<=MAX_K; j+=i){
			sum2 += sum[j];
		}
		if(sum2==N){
			ans = i;
		}
	}
	cout<<ans;
	return 0;
}