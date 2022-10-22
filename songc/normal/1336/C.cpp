#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
#define INF (1ll<<62)
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M;
char S[3030], T[3030];
LL D[3030][3030];
bool chk[3030][3030];

LL f(int s, int e){
	if (chk[s][e]) return D[s][e];
	chk[s][e] = true;
	if (s>1 && (s-1>M || T[s-1] == S[e-s+2])) D[s][e] = f(s-1, e);
	if (e<N && (e+1>M || T[e+1] == S[e-s+2])) D[s][e] = (D[s][e] + f(s, e+1))%MOD;
	if (s==1 && e>=M) D[s][e] = (D[s][e]+1)%MOD;
	return D[s][e];
}

int main(){
	scanf("%s", S+1);
	scanf("%s", T+1);
	N=strlen(S+1), M=strlen(T+1);
	LL ans=0;
	for (int i=1; i<=N; i++) if (i>M || T[i] == S[1]) ans=(ans+f(i, i))%MOD;
	printf("%lld\n", ans*2%MOD);
	return 0;
}