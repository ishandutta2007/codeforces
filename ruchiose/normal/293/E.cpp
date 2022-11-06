// Author: Ruchiose
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

#include<queue>
#include<vector>
#include<map>
#include<set>

struct Treap
{
    Treap *S[2];
    int Key, Rank, Size;
};

namespace GC
{
	queue<Treap*> buffer;
	Treap* assign()
	{
		if (buffer.size() == 0) return new Treap;
		Treap* ret = buffer.front();
		buffer.pop();
		return ret;
	}
	void deassign(Treap* x)
	{
		buffer.push(x);
	}
};

int Sz(Treap *Cur)
{
    if (Cur == NULL) return 0;
    return Cur->Size;
};

void Resize(Treap *&Cur)
{
    Cur->Size = 1 + Sz(Cur->S[0]) + Sz(Cur->S[1]);
};

void Rotate(Treap *&Cur, int From)
{
    Treap *Sid = Cur->S[From];
    Cur->S[From] = Sid->S[1 - From];
    Sid->S[1 - From] = Cur;
    Resize(Cur); Resize(Sid);
    Cur = Sid;
};

void Insert(Treap *&Cur, int NewKey, bool Pivot) // Pivot:  Rank < 0 
{
    if (Cur == NULL)
        {
            Cur = new Treap;
            Cur->S[0] = Cur->S[1] = NULL;
            Cur->Key = NewKey; Cur->Rank = (Pivot) ? (-1) : rand(); Cur->Size = 1;
            return;
        };
    if (NewKey <= Cur->Key)
        {
            Insert(Cur->S[0], NewKey, Pivot);
            if (Cur->S[0]->Rank < Cur->Rank) Rotate(Cur, 0);
            Resize(Cur);
        }
    else
        {
            Insert(Cur->S[1], NewKey, Pivot);
            if (Cur->S[1]->Rank < Cur->Rank) Rotate(Cur, 1);
            Resize(Cur);
        };
};

void destruct(Treap* x)
{
	if (x == NULL) return;
	destruct(x->S[0]);
	destruct(x->S[1]);
	GC::deassign(x);
}

int countAtMost(Treap* cur, int R)
{
	if (cur == NULL) return 0;
	if (R < cur->Key) return countAtMost(cur->S[0], R);
	return Sz(cur->S[0]) + 1 + countAtMost(cur->S[1], R);
}

struct Set
{
	Treap* treap;
	void destruct()
	{
		::destruct(treap);
	}
	void init()
	{
		destruct();
		treap = NULL;
	}
	Set()
	{
		treap = NULL;
		init();
	}
	void insert(int x)
	{
		Insert(treap, x, false);
	}
	int query(int r)
	{
		return countAtMost(treap, r);
	}
};

typedef pair<int,int> PII;

inline bool operator < (PII lhs, PII rhs)
{
	return (lhs.first == rhs.first) ? (lhs.second < rhs.second) : (lhs.first < rhs.first);
}

inline PII operator + (PII lhs, PII rhs)
{
	return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

const int MAXN = 100010;
const int MAXE = MAXN << 1;

int N, L, W, e[MAXE], enxt[MAXE], head[MAXN], ec;
PII w[MAXE];

void regi(int u, int v, PII w)
{
	e[++ec] = v; enxt[ec] = head[u]; head[u] = ec;
	::w[ec] = w;
}

bool sig[MAXN];

struct vlist
{
	vector<PII> B;
	void printList()
	{
		for (vector<PII>::iterator it = B.begin(); it != B.end(); it++)
			printf("(%d, %d)\n", it->first, it->second);
	}
	void init()
	{
		B.clear();
	}
	inline void simply_attach(PII r)
	{
		B.push_back(r);
	}
	inline void sort()
	{
		::sort(B.begin(), B.end());
	} 
	void attach(vlist &rhs)
	{
		static vector<PII> ans; ans.clear();
		vector<PII>::iterator itl = B.begin(), itr = rhs.B.begin();
		while ((itl != B.end()) || (itr != rhs.B.end()))
			{
				int id = 0;
				if (itl == B.end()) id = 1;
				if (itr == rhs.B.end()) id = -1;
				if (id == 0)
					id = (*itl < *itr) ? -1 : 1;
				if (id == -1)
					{
						ans.push_back(*itl);
						itl++;
					}
				else
					{
						ans.push_back(*itr);
						itr++;
					}
			}
		B = ans;
	}
	i64 cntLink(vlist &rhs)
	{
		Set t;
		t.init();
		vector<PII>::iterator itl = B.begin();
		i64 Ans = 0;
		for (vector<PII>::reverse_iterator itr = rhs.B.rbegin(); itr != rhs.B.rend(); itr++)
			{
				while ((itl != B.end()) && (itl->first + itr->first <= L))
					{
						t.insert(itl->second);
						itl++;
					}
				Ans += t.query(W - itr->second);
			}
		return Ans;
	}
};

int Size[MAXN];
int prev[MAXN], pree[MAXN];
vector<int> Q;

void bfs(int x)
{
	Q.clear();
	int H = 0;
	Q.push_back(x); sig[x] = false;
	while (H < Q.size())
		{
			for (int E = head[Q[H]]; E; E = enxt[E])
				if (sig[e[E]])
					{
						prev[e[E]] = Q[H];
						pree[e[E]] = E;
						Q.push_back(e[E]);
						sig[e[E]] = false;
					}
			H++;
		}
	for (vector<int>::iterator it = Q.begin(); it != Q.end(); it++) sig[*it] = true;
}

void bfs_makesize(int cur)
{
	bfs(cur);
	for (vector<int>::iterator it = Q.begin(); it != Q.end(); it++) Size[*it] = 1;
	for (vector<int>::reverse_iterator it = Q.rbegin(); it < Q.rend() - 1; it++)
		Size[prev[*it]] += Size[*it];
};

PII DIST[MAXN];

void bfs_distance(int x, PII d, vlist &v)
{
	bfs(x);
	DIST[x] = d;
	for (vector<int>::iterator it = Q.begin() + 1; it != Q.end(); it++)
		DIST[*it] = DIST[prev[*it]] + w[pree[*it]];
	for (vector<int>::iterator it = Q.begin(); it != Q.end(); it++)
		v.simply_attach(DIST[*it]);
}

i64 Ans = 0;

void process(int x)
{
	bfs_makesize(x);
	int centroid = x;
	do
		{
			int maxsub = 0;
			for (int E = head[centroid]; E; E = enxt[E])
				if ((sig[e[E]]) && (Size[e[E]] < Size[centroid]))
					maxsub = max(maxsub, Size[e[E]]);
			if (maxsub <= Size[x] / 2) break;
			for (int E = head[centroid]; E; E = enxt[E])
				if ((sig[e[E]]) && (Size[e[E]] == maxsub))
					{
						centroid = e[E];
						break;
					}
		}
	while (1);
	//printf("centroid = %d\n", centroid);
	sig[centroid] = false;
	static set<PII> sz_id;
	static map<int,vlist> id_list;
	sz_id.clear();
	id_list.clear();
	sz_id.insert(make_pair(1, centroid)); // the Centroid
	id_list[centroid].simply_attach(make_pair(0, 0));
	for (int E = head[centroid]; E; E = enxt[E])
		if (sig[e[E]])
			{
				id_list[e[E]];
				bfs_distance(e[E], w[E], id_list[e[E]]);
				id_list[e[E]].sort();
				sz_id.insert(make_pair(id_list[e[E]].B.size(), e[E]));
			}
	while (sz_id.size() > 1)
		{
			int set1 = sz_id.begin()->second;
			sz_id.erase(sz_id.begin());
			int set2 = sz_id.begin()->second;
			sz_id.erase(sz_id.begin());
			Ans += id_list[set1].cntLink(id_list[set2]);
			id_list[set1].attach(id_list[set2]);
			id_list.erase(set2);
			sz_id.insert(make_pair(id_list[set1].B.size(), set1));
		}
}

int main()
{
	scanf("%d%d%d", &N, &L, &W);
	int i;
	fortodo(i, 1, N) head[i] = 0; ec = 0;
	fortodo(i, 2, N)
		{
			int pi, wi;
			scanf("%d%d", &pi, &wi);
			//pi = i - 1; wi = 0;
			regi(pi, i, make_pair(1, wi));
			regi(i, pi, make_pair(1, wi));
		}
	fortodo(i, 1, N) sig[i] = true;
	Ans = 0;
	fortodo(i, 1, N)
		while (sig[i])
			process(i);
	cout << Ans << endl;
}