#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXS = 1000010;
const int sigma = 26;

char S[MAXS];
int N, Q, i, j;

struct SAM
{
	SAM *parent, *s[sigma];
	int Len, Cnt;
	SAM()
	{
		parent = NULL;
		int i;
		fortodo(i, 0, sigma - 1) s[i] = NULL;
		Len = Cnt = 0;
	}
};

SAM *e[MAXS<<1], *genesis, *tail;
int e0;

void extend(int ch)
{
	SAM *np, *vi, *scape, *sprite;
	e[++e0] = np = new SAM;
	np->Len = tail->Len + 1;
	np->Cnt = 1;
	for (vi = tail; (vi) && (!(scape = vi->s[ch])); vi = vi->parent)
		vi->s[ch] = np;
	if (!vi) np->parent = genesis; else
	if (vi->Len + 1 == scape->Len) np->parent = scape; else
	{
		e[++e0] = sprite = new SAM;
		*sprite = *scape;
		sprite->Cnt = 0;
		sprite->Len = vi->Len + 1;
		np->parent = scape->parent = sprite;
		for (; (vi) && (vi->s[ch] == scape); vi = vi->parent) vi->s[ch] = sprite;
	}
	tail = np;
}

bool cmp_pslza(SAM* a, SAM* b)
{
	return (a->Len > b->Len);
}

SAM *wit;
int L;

void evol(int ch)
{
	if (wit->s[ch])
		{
			L++;
			wit = wit->s[ch];
		}
	else
		{
			while ((wit) && (!wit->s[ch])) wit = wit->parent;
			if (wit) L = wit->Len + 1, wit = wit->s[ch];
			else wit = genesis, L = 0;
		}
}

int fail[MAXS], P0;
char P[MAXS];

int Query()
{
	scanf("%s", P + 1);
	P0 = strlen(P + 1);
	int p = fail[1] = 0, i;
	fortodo(i, 2, P0)
		{
			while ((p) && (P[p + 1] != P[i])) p = fail[p];
			if (P[p + 1] == P[i]) p++;
			fail[i] = p;
		}
	int Cir = P0 - fail[P0];
	if (P0 % Cir) Cir = P0;
	int ANS = 0;
	wit = genesis; L = 0;
	fortodo(i, 1, P0 - 1) evol(P[i] - 'a');
	P[0] = P[P0];
	fortodo(i, 0, Cir - 1)
		{
			evol(P[i] - 'a');
			if (L >= P0)
				{
					if (wit->parent->Len >= P0) wit = wit->parent;
					ANS += wit->Cnt;
				}
		}
	return ANS;
}

int main()
{
	scanf("%s", S + 1);
	N = strlen(S + 1);
	e[e0 = 0] = genesis = tail = new SAM;
	genesis->Cnt = 1;
	fortodo(i, 1, N) extend(S[i] - 'a');
	sort(e, e + e0 + 1, cmp_pslza);
	fortodo(i, 0, e0)
		if (e[i]->parent)
			e[i]->parent->Cnt += e[i]->Cnt;
	for (scanf("%d", &Q); Q; Q--) printf("%d\n", Query());
}