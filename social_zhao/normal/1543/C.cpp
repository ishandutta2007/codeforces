#include<bits/stdc++.h>
#define double long double
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

double c, m, p, v, pc, pm, ans;

void dfs(int dep, double now) {
	if(fabs(pc) > 1e-10) {
		double prc = pc, prm = pm, prp = p, nxt = now * pc, delt = min(v, pc);
		pc -= delt;
		if(fabs(pm) > 1e-10) pm += delt / 2, p += delt / 2;
		else p += delt;
		dfs(dep + 1, nxt), pc = prc, pm = prm, p = prp;
	}
	if(fabs(pm) > 1e-10) {
		double prc = pc, prm = pm, prp = p, nxt = now * pm, delt = min(v, pm);
		pm -= delt;
		if(fabs(pc) > 1e-10) pc += delt / 2, p += delt / 2;
		else p += delt;
		dfs(dep + 1, nxt), pc = prc, pm = prm, p = prp;
	}
	ans += dep * now * p;
}

void solve() {
	scanf("%Lf%Lf%Lf%Lf", &c, &m, &p, &v);
	ans = 0;
	pc = c, pm = m, dfs(1, 1);
	printf("%.10Lf\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}