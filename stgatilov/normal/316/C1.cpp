//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 84;
const int VERTS = SIZE*SIZE;

int n, m;
int v, s, t;
int pict[SIZE][SIZE];

const int dir[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
inline bool good(int x, int y) { return x>=0 && y>=0 && x<n && y<m; }

struct Edge {
	int a, b;
	int flow;
	int cap, cost;
	int anti;
};
vector<Edge> edges;
vector<int> nbr[VERTS];

void AddEdge(int a, int b, int cap, int cost) {
	Edge e1;
	e1.a = a;
	e1.b = b;
	e1.flow = 0;
	e1.cap = cap;
	e1.cost = cost;
	e1.anti = edges.size() + 1;
	Edge e2;
	e2.a = b;
	e2.b = a;
	e2.flow = 0;
	e2.cap = 0;
	e2.cost = -cost;
	e2.anti = edges.size();
	nbr[a].push_back(edges.size());
	nbr[b].push_back(edges.size() + 1);
	edges.push_back(e1);
	edges.push_back(e2);
}

bool used[VERTS];
int dist[VERTS];
int father[VERTS];
int phi[VERTS];

struct Comparator {
	inline bool operator() (int a, int b) const {
		if (dist[a] != dist[b])
			return dist[a] < dist[b];
		return a < b;
	}
};

char space[1<<24];
int spck;
template<class T> class MyAllocator : public allocator<T> {
public:
	T *allocate(size_t n) const {
//		fprintf(stderr, "%d\n", spck);
		T *res = (T*)&space[spck];
		spck += sizeof(T);
		return res;
	}
	void deallocate(T *p, size_t n) const {
	}

	template<class Other> struct rebind {
		typedef MyAllocator<Other> other;
	};
	MyAllocator() {}
	template<class Other> MyAllocator(const MyAllocator<Other>& q) {}
};

bool Dijkstra(int &allFlow, int &allCost) {
	memset(dist, 63, sizeof(dist));
	memset(father, -1, sizeof(father));
	memset(used, false, sizeof(used));
	dist[s] = 0;

	spck = 0;
	set<int, Comparator, MyAllocator<int> > heap;
	for (int i = 0; i<v; i++) heap.insert(i);

	while (!heap.empty()) {
		int best = *heap.begin();
		if (dist[best] > 1000000000) break;

		heap.erase(heap.begin());
		if (best < 0) break;
		used[best] = true;

		for (int i = 0; i<nbr[best].size(); i++) {
			int eidx = nbr[best][i];
			const Edge& e = edges[eidx];
			if (used[e.b]) continue;
			if (e.flow == e.cap) continue;

			int newd = dist[best] + e.cost + phi[best] - phi[e.b];
			if (dist[e.b] > newd) {
				heap.erase(e.b);
				dist[e.b] = newd;
				heap.insert(e.b);
				father[e.b] = eidx;
			}
		}
	}
	heap.clear();

	if (!used[t]) return false;

	allFlow++;

	int curr = t;
	while (curr != s) {
		int eidx = father[curr];
		Edge &e = edges[eidx];
		int pp = e.a;
		e.flow++;
		edges[e.anti].flow--;
		allCost += e.cost;
		curr = pp;
	}

	for (int i = 0; i<v; i++) if (used[i])
		phi[i] += dist[i];

	return true;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			scanf("%d", &pict[i][j]);

	s = n*m;
	t = n*m + 1;
	v = n*m + 2;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) {
			if ((i+j)&1) {
				AddEdge(s, i*m+j, 1, 0);
				for (int d = 0; d<4; d++) {
					int ni = i + dir[d][0];
					int nj = j + dir[d][1];
					if (!good(ni, nj)) continue;
					AddEdge(i*m+j, ni*m+nj, 1, pict[i][j] != pict[ni][nj]);
				}
			}
			else
				AddEdge(i*m+j, t, 1, 0);
		}

	int tflow = 0, tcost = 0;
	while (Dijkstra(tflow, tcost)) fprintf(stderr, "!");

//	printf("%d %d\n", tflow, tcost);
	printf("%d\n", tcost);

	return 0;
}