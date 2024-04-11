// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

struct SEG
{
	SEG *s[2];
	i64 Max;
	int Key;
	SEG()
	{
		s[0] = s[1] = NULL;
		Max = Key = 0;
	}
};

SEG *seg;

void EMP(SEG* &cur, int L, int R)
{
	if (cur == NULL) cur = new SEG;
	cur->Max = cur->Key = 0;
	if (L == R) return;
	int Mid = (L + R) / 2;
	EMP(cur->s[0], L, Mid);
	EMP(cur->s[1], Mid + 1, R);
}

void INS(SEG* cur, int L, int R, int B, i64 V, int K)
{
	if (V > cur->Max)
		{
			cur->Max = V;
			cur->Key = K;
		}
	if (L != R)
		{
			int Mid = (L + R) / 2;
			if (B <= Mid)
				INS(cur->s[0], L, Mid, B, V, K);
			else
				INS(cur->s[1], Mid + 1, R, B, V, K);
		}
}

pair<i64,int> QRY(SEG* cur, int L, int R, int l, int r)
{
	if ((L == l) && (R == r))
		return make_pair(cur->Max, cur->Key);
	int Mid = (L + R) / 2;
	if (r <= Mid) return QRY(cur->s[0], L, Mid, l, r);
	if (l > Mid) return QRY(cur->s[1], Mid + 1, R, l, r);
	pair<i64,int> LANS, RANS;
	LANS = QRY(cur->s[0], L, Mid, l, Mid);
	RANS = QRY(cur->s[1], Mid + 1, R, Mid + 1, r);
	if (LANS.first > RANS.first)
		return LANS;
	else
		return RANS;
}

const int MAXN = 200010;

int N, M;
int L[MAXN], R[MAXN], A[MAXN], B[MAXN], C[MAXN];
int S[MAXN * 4], O;

#include<vector>

vector<int> VecA[MAXN * 4], VecB[MAXN * 4];

i64 ANS, SCHN, SCHM;

void ADD(int schn, int schm)
{
	int len = min(S[R[schn]], S[B[schm]]) - max(S[L[schn]], S[A[schm]]);
	if (len * 1LL * C[schm] > ANS)
		{
			ANS = len * 1LL * C[schm];
			SCHN = schn;
			SCHM = schm;
		}
}

int main()
{
	scanf("%d%d", &N, &M);
	int i;
	fortodo(i, 1, N) scanf("%d%d", &L[i], &R[i]);
	fortodo(i, 1, M) scanf("%d%d%d", &A[i], &B[i], &C[i]);
	O = 0;
	fortodo(i, 1, N)
		{
			S[++O] = L[i];
			S[++O] = R[i];
		}
	fortodo(i, 1, M)
		{
			S[++O] = A[i];
			S[++O] = B[i];
		}
	sort(S + 1, S + O + 1);
	fortodo(i, 1, N)
		{
			L[i] = lower_bound(S + 1, S + O + 1, L[i]) - S;
			R[i] = lower_bound(S + 1, S + O + 1, R[i]) - S;
		}
	fortodo(i, 1, M)
		{
			A[i] = lower_bound(S + 1, S + O + 1, A[i]) - S;
			B[i] = lower_bound(S + 1, S + O + 1, B[i]) - S;
		}
	seg = NULL;
	EMP(seg, 1, O);
	fortodo(i, 1, O)
		{
			VecA[i].clear();
			VecB[i].clear();
		}
	fortodo(i, 1, N)
		VecA[L[i]].push_back(i);
	fortodo(i, 1, M)
		VecB[A[i]].push_back(i);
	ANS = 0;
	#define FOREACH(it, vi) for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
	// [ () ]
	fortodo(i, 1, O)
		{
			FOREACH(it, VecB[i])
				INS(seg, 1, O, B[*it], C[*it], *it);
			FOREACH(it, VecA[i])
				{
					pair<i64,int> RET = QRY(seg, 1, O, R[*it], O);
					if (RET.first) ADD(*it, RET.second);
				}
		}
	EMP(seg, 1, O);
	// ( [] )
	fortodo(i, 1, O)
		{
			FOREACH(it, VecA[i])
				INS(seg, 1, O, R[*it], 1, *it);
			FOREACH(it, VecB[i])
				{
					pair<i64,int> RET = QRY(seg, 1, O, B[*it], O);
					if (RET.first) ADD(RET.second, *it);
				}
		}
	EMP(seg, 1, O);
	// ( [ ) ]
	fortodo(i, 1, O)
		{
			FOREACH(it, VecA[i])
				INS(seg, 1, O, R[*it], R[*it], *it);
			FOREACH(it, VecB[i])
				{
					pair<i64,int> RET = QRY(seg, 1, O, A[*it], B[*it]);
					if (RET.first) ADD(RET.second, *it);
				}
		}
	EMP(seg, 1, O);
	// [ ( ] )
	fortodo(i, 1, O)
		{
			VecA[i].clear();
			VecB[i].clear();
		}
	fortodo(i, 1, N)
		VecA[R[i]].push_back(i);
	fortodo(i, 1, M)
		VecB[B[i]].push_back(i);
	for (i = O; i; i--)
		{
			FOREACH(it, VecA[i])
				INS(seg, 1, O, L[*it], O + 1 - L[*it], *it);
			FOREACH(it, VecB[i])
				{
					pair<i64,int> RET = QRY(seg, 1, O, A[*it], B[*it]);
					if (RET.first) ADD(RET.second, *it);
				}
		}
	EMP(seg, 1, O);
	cout << ANS << endl;
	if (ANS) cout << SCHN << " " << SCHM << endl;
	return 0;
}