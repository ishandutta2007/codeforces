// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int undefined = 0;
const int typeLeaf = 0;
const int typePerm = 1;
const int typeRev = 2;

struct PQTree
{
	int type, mes;
	vector<PQTree*> sub;
	void init()
	{
		sub.clear();
		type = typeLeaf;
		mes = undefined;
	}
	PQTree()
	{
		init();
	}
};

namespace GC
{
	stack<PQTree*> buffer;
	void release()
	{
		while (buffer.size()) buffer.pop();
	}
	PQTree* assign()
	{
		if (buffer.size())
			{
				PQTree* ret = buffer.top();
				buffer.pop();
				ret->init();
				return ret; 
			}
		else
			return new PQTree;
	}
	PQTree* assign_leaf(int l)
	{
		PQTree* ret = assign();
		ret->mes = l;
		return ret;
	}
	void deassign(PQTree* x)
	{
		buffer.push(x);
	}
};

int N, C[510][510];

PQTree* Universal(int N)
{
	if (N == 1) return GC::assign_leaf(1);
	PQTree* root = GC::assign();
	root->type = typePerm;
	int i;
	fortodo(i, 1, N) root->sub.push_back(GC::assign_leaf(i));
	return root;
}

PQTree* pqtree;

void claimNoSol()
{
	printf("NO\n");
	exit(0);
}

PQTree* Pertinent(PQTree* ths, int* E)
{
	if (ths->type == typeLeaf)
		return (E[ths->mes]) ? ths : NULL;
	PQTree* ret = NULL;
	for (vector<PQTree*>::iterator it = ths->sub.begin(); it != ths->sub.end(); it++)
		{
			PQTree* sret = Pertinent(*it, E);
			if (ret == NULL)
				ret = sret;
			else
				if (sret)
					ret = ths;
		}
	return ret;
}

const int sigEmpty = 0;
const int sigFull = 1;
const int sigPartial = 2;
const int sigRoot = 3;

PQTree* groupIt(vector<PQTree*> &g)
{
	PQTree* grouped;
	if (g.size() == 1)
		grouped = g[0];
	else
		{
			grouped = GC::assign();
			grouped->type = typePerm;
			grouped->sub = g;
		}
	return grouped;
}

bool allEqual(vector<int>::iterator S, vector<int>::iterator E, int x)
{
	while (S < E)
		{
			if (*S != x) return false;
			S++;
		} 
	return true;
}

int Reduce(PQTree* cur, int* E, bool isRoot)
{
	switch (cur->type)
	{
		case typeLeaf:
			return E[cur->mes] ? sigFull : sigEmpty;
		break;
		case typePerm:{
			vector<PQTree*> sj[3];
			sj[sigEmpty].clear();
			sj[sigFull].clear();
			sj[sigPartial].clear();
			for (vector<PQTree*>::iterator it = cur->sub.begin(); it != cur->sub.end(); it++)
				sj[Reduce(*it, E, false)].push_back(*it);
			if (sj[sigPartial].size() == 0)
				{
					if (sj[sigFull].size() == 0) return sigEmpty; // P0
					if (sj[sigFull].size() == cur->sub.size()) return sigFull; // P1
					if (isRoot)
						{
							// P2
							cur->sub = sj[sigEmpty];
							cur->sub.push_back(groupIt(sj[sigFull]));
							return sigRoot;
						}
					else
						{
							// P3
							cur->sub.clear();
							cur->type = typeRev;
							cur->sub.push_back(groupIt(sj[sigEmpty]));
							cur->sub.push_back(groupIt(sj[sigFull]));
							return sigPartial;
						}
				}
			if (sj[sigPartial].size() == 1)
				if (isRoot)
					{
						// P4
						if (sj[sigFull].size())
							{
								cur->sub = sj[sigEmpty];
								cur->sub.push_back(sj[sigPartial][0]);
								cur->sub.back()->sub.push_back(groupIt(sj[sigFull]));
							}
						return sigRoot;
					}
				else
					{
						// P5
						cur->sub.clear();
						cur->type = typeRev;
						if (sj[sigEmpty].size()) cur->sub.push_back(groupIt(sj[sigEmpty]));
						cur->sub.insert(cur->sub.end(), sj[sigPartial][0]->sub.begin(), sj[sigPartial][0]->sub.end());
						if (sj[sigFull].size()) cur->sub.push_back(groupIt(sj[sigFull]));
						return sigPartial;
					}
			if (sj[sigPartial].size() == 2)
				{
					if (!isRoot) claimNoSol();
					// P6
					cur->sub = sj[sigEmpty];
					cur->sub.push_back(sj[sigPartial][0]);
					if (sj[sigFull].size())
						cur->sub.back()->sub.push_back(groupIt(sj[sigFull]));
					reverse(sj[sigPartial][1]->sub.begin(), sj[sigPartial][1]->sub.end());
					cur->sub.back()->sub.insert(cur->sub.back()->sub.end(), sj[sigPartial][1]->sub.begin(), sj[sigPartial][1]->sub.end());
					GC::deassign(sj[sigPartial][1]);
					return sigRoot;
				}
			claimNoSol();
		}break;
		case typeRev:{
			vector<int> rets;
			rets.clear();
			for (vector<PQTree*>::iterator it = cur->sub.begin(); it != cur->sub.end(); it++)
				rets.push_back(Reduce(*it, E, false));
			if (allEqual(rets.begin(), rets.end(), sigEmpty)) return sigEmpty; // Q0
			if (allEqual(rets.begin(), rets.end(), sigFull)) return sigFull; // Q1
			vector<int> partialIdx;
			partialIdx.clear();
			for (vector<int>::iterator it = rets.begin(); it != rets.end(); it++)
				if (*it == sigPartial)
					partialIdx.push_back(it - rets.begin());
			int firstPertinent, lastPertinent;
			for (vector<int>::iterator it = rets.begin(); it != rets.end(); it++)
				if (*it != sigEmpty)
					{
						firstPertinent = it - rets.begin();
						break;
					}
			for (vector<int>::iterator it = rets.begin(); it != rets.end(); it++)
				if (*it != sigEmpty)
					lastPertinent = it - rets.begin();
			if (!allEqual(rets.begin() + firstPertinent + 1, rets.begin() + lastPertinent, sigFull))
				claimNoSol();
			if ((firstPertinent == lastPertinent) && (isRoot))
				{
					// Q3: special case
					return sigRoot;
				}
			if ((lastPertinent == 0) && (rets[0] == sigPartial))
				{
					// Q2: special case L
					PQTree* s = cur->sub[0];
					cur->sub.erase(cur->sub.begin());
					reverse(cur->sub.begin(), cur->sub.end());
					cur->sub.insert(cur->sub.end(), s->sub.begin(), s->sub.end());
					GC::deassign(s);
					return sigPartial;
				}
			if ((firstPertinent == rets.size() - 1) && (rets.back() == sigPartial))
				{
					// Q2: special case R
					PQTree* s = cur->sub.back();
					cur->sub.pop_back();
					cur->sub.insert(cur->sub.end(), s->sub.begin(), s->sub.end());
					GC::deassign(s);
					return sigPartial;
				}
			if ((firstPertinent == 0) && (rets[0] == sigFull))
				{
					// Q2: usual case L
					if (rets[lastPertinent] == sigPartial)
						{
							PQTree* s = cur->sub[lastPertinent];
							reverse(s->sub.begin(), s->sub.end());
							cur->sub.erase(cur->sub.begin() + lastPertinent);
							cur->sub.insert(cur->sub.begin() + lastPertinent, s->sub.begin(), s->sub.end());
							GC::deassign(s);
						}
					reverse(cur->sub.begin(), cur->sub.end());
					return sigPartial;
				}
			if ((lastPertinent == rets.size() - 1) && (rets.back() == sigFull))
				{
					// Q2: usual case R
					if (rets[firstPertinent] == sigPartial)
						{
							PQTree* s = cur->sub[firstPertinent];
							cur->sub.erase(cur->sub.begin() + firstPertinent);
							cur->sub.insert(cur->sub.begin() + firstPertinent, s->sub.begin(), s->sub.end());
							GC::deassign(s);
						}
					return sigPartial;
				}
			if (isRoot)
				{
					// Q3
					if (rets[lastPertinent] == sigPartial)
						{
							PQTree* s = cur->sub[lastPertinent];
							reverse(s->sub.begin(), s->sub.end());
							cur->sub.erase(cur->sub.begin() + lastPertinent);
							cur->sub.insert(cur->sub.begin() + lastPertinent, s->sub.begin(), s->sub.end());
							GC::deassign(s);
						}
					if (rets[firstPertinent] == sigPartial)
						{
							PQTree* s = cur->sub[firstPertinent];
							cur->sub.erase(cur->sub.begin() + firstPertinent);
							cur->sub.insert(cur->sub.begin() + firstPertinent, s->sub.begin(), s->sub.end());
							GC::deassign(s);
						}
					return sigRoot;
				}
			claimNoSol(); 	
		}break;
	}
}

vector<int> SEQ;

void walk(PQTree* cur)
{
	if (cur->type == typeLeaf)
		SEQ.push_back(cur->mes);
	else
		for (vector<PQTree*>::iterator it = cur->sub.begin(); it != cur->sub.end(); it++)
			walk(*it);
}

int main()
{
	scanf("%d", &N);
	int i, j;
	fortodo(i, 1, N)
		{
			char ch[510];
			scanf("%s", ch + 1);
			fortodo(j, 1, N)
				C[i][j] = ch[j] - '0';
		}
	GC::release();
	pqtree = Universal(N);
	fortodo(i, 1, N)
		{
			PQTree* pertinent = Pertinent(pqtree, C[i]);
			if (pertinent == NULL) continue;
			Reduce(pertinent, C[i], true);
		}
	printf("YES\n");
	SEQ.clear();
	walk(pqtree);
	fortodo(i, 1, N)
		{
			fortodo(j, 0, N - 1)
				putchar('0' + C[i][SEQ[j]]);
			puts("");
		}
}