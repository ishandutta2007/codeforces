#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define Forr(i, a, b) for(int i = (a); i >= (int)(b); --i)

#define LOG 32
#define N (100000+5)

int Pow(int a, int anum, int P){
	a %= P;

	int ret = 1;
	while(anum){
		if(anum & 1) ret = 1ll * ret * a % P;
		a = 1ll * a * a % P; anum >>= 1;
	}
	return ret;
}

int pn, w[N], pp[N];

int Phi(int now){
//	printf("Phi(%d) = ", now);

	int ret = now;
	for(int i = 2; i*i <= now; ++i) if(now % i == 0){
		ret = ret - ret/i;
		while(now % i == 0) now /= i;
	}
	if(now > 1) ret = ret - ret/now;
	
//	printf("%d\n", ret);

	return ret;
}

void Init(int np){
	pp[0] = np; np = pp[0];

	while(np > 1){
		pp[++pn] = Phi(np);
		np = pp[pn];
	}
}

int pos[N];

bool Calc(int L, int R, int P){
	R = min(R, pos[L]);

	int nxt, now = w[R], tmp = R-1;
	while(tmp >= L && now < P){
		nxt = w[tmp];
		if(w[tmp] >= P) return true;

		For(i, 2, now){
			if(1ll*nxt*w[tmp] >= 1ll*P) return true;
			nxt *= w[tmp];
		}
		now = nxt; --tmp;
	}

	return now >= P;
}

int Solve(int now, int R, int P, int dep){
	if(now == R || P == 1) return w[now] % P;

	int nv = Solve(now+1, R, pp[dep+1], dep+1);
	if(Calc(now+1, R, pp[dep+1])) nv += pp[dep+1];

	return Pow(w[now], nv, P);
}

int main(){
//	freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);

	int n, P, Q, L, R;
	
	scanf("%d%d", &n, &P);
	For(i, 1, n) scanf("%d", &w[i]);
	
	int lst = n+1;
	Forr(i, n, 1){
		if(w[i] == 1) lst = i;
		pos[i] = lst;
	}

	Init(P);

	scanf("%d", &Q);
	while(Q--){
		scanf("%d%d", &L, &R);
		printf("%d\n", Solve(L, R, P, 0));
	}
	
	return 0;
}