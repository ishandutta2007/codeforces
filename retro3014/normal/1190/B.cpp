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

int N;
vector<int> vt;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x); vt.pb(x);
	}
	sort(vt.begin(), vt.end());
	int cnt = 0;
	for(int i=0; i<N-1; i++){
		if(vt[i]==vt[i+1])	cnt++;
		if(vt[i]==vt[i+1] && i!=0 && vt[i-1]==vt[i]-1){
			printf("cslnb");
			return 0;
		}
		if(vt[i]==vt[i+1] && vt[i]==0){
			printf("cslnb");
			return 0;
		}
	}
	if(cnt>1){
		printf("cslnb");
		return 0;
	}
	int x = 0;
	int t = 0;
	for(int i=0; i<N; i++){
		t = (t + (vt[i] - x)) % 2;
		x ++;
	}
	if(t%2){
		printf("sjfnb");
	}else{
		printf("cslnb");
	}

	return 0;
}