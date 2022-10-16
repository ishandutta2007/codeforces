#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int L = N * N;

int n;

struct Point
{
	int x, y;
	Point(){}
	Point(int x, int y) { this->x = x, this->y = y; }
	Point(int read) { scanf("%d%d", &x, &y); }
	Point rot() { return Point(y, -x); }
	int sgn() { return (y >= 0 && x >= 0) || (y > 0 && x < 0); }
	void print() { printf("%d %d\n", x, y); }
};

typedef Point Vec;

Vec operator + (const Vec &p, const Vec &q) { return Vec(p.x + q.x, p.y + q.y); }
Vec operator - (const Vec &p, const Vec &q) { return Vec(p.x - q.x, p.y - q.y); }
Vec operator - (const Vec &p) { return Vec(-p.x, -p.y); }
long long operator * (const Vec &p, const Vec &q) { return 1ll * p.x * q.y - 1ll * q.x * p.y; }

struct Event
{
	Vec n;
	int A, B;
	Event(){}
	Event(const Vec &n, int A, int B) { this->n = n, this->A = A, this->B = B; }
};

bool operator < (Event &e1, Event &e2)
{
	if (e1.n.sgn() != e2.n.sgn())
		return e1.n.sgn() > e2.n.sgn();
	return e1.n * e2.n < 0;
}

Point P[N];
Event e[L];
Vec vn[L];
int p[N], rk[N];
int cnt;

bool cmp(int x, int y)
{
	if (P[x].x != P[y].x)
		return P[x].x > P[y].x;
	return P[x].y < P[y].y;
}

long long S;

int main()
{
	scanf("%d%lld", &n, &S);
	for (int i = 1; i <= n; i++)
	{
		P[i] = Point(0);
		p[i] = i;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			e[++cnt] = Event((P[i] - P[j]).rot(), i, j);
			e[++cnt] = Event((P[j] - P[i]).rot(), j, i);
		}
	sort(e + 1, e + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		vn[i] = e[i].n.rot();
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		rk[p[i]] = i;
	S <<= 1;
	for (int i = 1; i <= cnt; i++)
	{
		swap(p[rk[e[i].A]], p[rk[e[i].B]]);
		swap(rk[e[i].A], rk[e[i].B]);
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (vn[i] * (P[p[mid]] - P[e[i].A]) < S)
				l = mid + 1;
			else
				r = mid;
		}
		if (vn[i] * (P[p[l]] - P[e[i].A]) == S)
		{
			printf("Yes\n");
			P[e[i].A].print();
			P[e[i].B].print();
			P[p[l]].print();
			return 0;
		}
	}
	printf("No\n");
	return 0;
}