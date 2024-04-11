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

const int MAX_N = 100000;

struct P{
	ll x, y;
};
P S, E;
ll N;
string str;
ll dx[MAX_N+1], dy[MAX_N+1];

ll zero(ll x){
	if(x>0)	return x;
	return -x;
}

bool chk(ll x){
	ll cx = 0, cy = 0;
	cx += (dx[N] * ((x-1)/N)); cy += (dy[N] * ((x-1)/N));
	cx += dx[(x-1)%N+1]; cy += dy[(x-1)%N+1];
	ll move = zero(E.x - S.x - cx) + zero(E.y - S.y - cy);
	return (move<=x);
}

int main(){
	scanf("%lld%lld", &S.x, &S.y); scanf("%lld%lld", &E.x, &E.y);
	scanf("%lld", &N);
	cin>>str;
	for(int i=1; i<=N; i++){
		dx[i] = dx[i-1]; dy[i] = dy[i-1];
		if(str[i-1]=='U')	dy[i]++;
		else if(str[i-1]=='D')dy[i]--;
		else if(str[i-1]=='L')	dx[i]--;
		else if(str[i-1]=='R')	dx[i]++;
	}
	ll s = 0, e = INFLL, m;
	while(s<e){
		m = (s+e)/2;
		if(chk(m))	e = m;
		else	 s = m+1;
	}
	if(chk(s)){
		printf("%lld", s);
	}else	printf("-1");
	return 0;
}