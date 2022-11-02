#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
int A[N_], B[N_], n, Q, Num[N_], par[N_], Ed[N_], cnt, ord[N_];
vector<int>E[N_];
long long BSum[N_], ASum[N_];
void DFS(int a, int pp) {
	par[a] = pp;
	Num[a] = ++cnt;
	ord[cnt] = a;
	ASum[a] = ASum[pp] + A[a];
	BSum[a] = BSum[pp] + B[a];
	for (auto &x : E[a]) {
		if (x != pp)DFS(x, a);
	}
	Ed[a] = cnt;
}
int BSZ = 150;
struct Seg {
	long long A, B;
	bool operator<(const Seg &p)const {
		return A != p.A ? A<p.A : B>p.B;
	}
};
struct DS {
	long long CurX, AS[210], BS[210], CCX;
	Seg Z[410], st[410];
	int sz, top, cnt, pv;
	void Spread() {
		int i;
		for (i = 0; i < cnt; i++) {
			AS[i] += CCX;
		}
		CCX = 0;
	}
	bool Over(Seg a, Seg b, Seg c) {
		return (long double)(a.B - b.B)/ (b.A - a.A) >= (long double)(a.B - c.B)/ (c.A - a.A);
	}
	void Build() {
		int i;
		sz = 0;
		CurX = 0;
		for (i = 0; i < cnt; i++) {
			int ck = 1;
			if (AS[i] < 0)ck = -1;
			Z[sz++] = { BS[i] * ck, abs(AS[i] * BS[i]) };
			Z[sz++] = { -BS[i] * ck , -abs(AS[i] * BS[i]) };
		}
		sort(Z, Z + sz);
		top = 0;
		for (i = 0; i < sz; i++) {
			if (i && Z[i].A == Z[i - 1].A)continue;
			while (top > 1 && Over(st[top - 1], st[top], Z[i])) top--;
			st[++top] = Z[i];
		}
		pv = 1;
	}
	void AddBlock(int a) {
		CCX += a;
		CurX += a;
	}
	void AddPartial(int b, int e, int a) {
		Spread();
		for (int i = b; i <= e; i++)AS[i] += a;
		Build();
	}
	long long Get() {
		while (pv < top && st[pv].A*CurX + st[pv].B <= st[pv + 1].A*CurX + st[pv + 1].B)pv++;
		return st[pv].A*CurX + st[pv].B;
	}
	long long GetMax(int b, int e) {
		Spread();
		long long res = 0;
		for (int i = b; i <= e; i++)res = max(res, abs(AS[i] * BS[i]));
		return res;
	}
}U[1510];
int main() {
	scanf("%d%d", &n, &Q);
	int i, a, b;
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
		E[i].push_back(a);
	}
	for (i = 1; i <= n; i++)scanf("%d", &A[i]);
	for (i = 1; i <= n; i++) scanf("%d", &B[i]);
	DFS(1, 0);
	for (i = 1; i <= n; i++) {
		int bb = (i - 1) / BSZ;
		int ck = 1;
		int x = ord[i];
		if (ASum[x] < 0)ck = -1;
		U[bb].AS[U[bb].cnt] = ASum[x];
		U[bb].BS[U[bb].cnt] = abs(BSum[x]);
		U[bb].cnt++;
	}
	int BN = (n - 1) / BSZ;
	for (i = 0; i <= BN; i++)U[i].Build();
	while (Q--) {
		int ck;
		scanf("%d%d", &ck, &a);
		if (ck == 2) {
			int b = Num[a], e = Ed[a];
			int bb = (b - 1) / BSZ, ee = (e - 1) / BSZ;
			int bp = (b - 1) % BSZ, ep = (e - 1) % BSZ;
			if (bb == ee) {
				printf("%lld\n", U[bb].GetMax(bp, ep));
			}
			else {
				long long r = 0;
				r = max(r, U[bb].GetMax(bp, U[bb].cnt - 1));
				r = max(r, U[ee].GetMax(0, ep));
				for (i = bb + 1; i < ee; i++)r = max(r, U[i].Get());
				printf("%lld\n", r);
			}
			continue;
		}
		int c, e;
		scanf("%d", &c);
		b = Num[a], e = Ed[a];
		int bb = (b - 1) / BSZ, ee = (e - 1) / BSZ;
		int bp = (b - 1) % BSZ, ep = (e - 1) % BSZ;
		if (bb == ee) {
			U[bb].AddPartial(bp, ep, c);
		}
		else {
			U[bb].AddPartial(bp, U[bb].cnt - 1, c);
			U[ee].AddPartial(0, ep, c);
			for (i = bb + 1; i < ee; i++)U[i].AddBlock(c);
		}
	}
}