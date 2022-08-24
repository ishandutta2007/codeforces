#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define x first
#define y second

int N, M;
pair <int, int> r[100100];

int lx, cr;
vector <pair <int, int> > p, np;

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		cin >> r[i].x >> r[i].y;
	
	sort (r, r + N);
	
	p.push_back (make_pair (1, 1));
	lx = cr = 0;
	
	while (cr < N)
	{
		if (r[cr].x != lx + 1 && p.size() > 0)
		{
			int lo = p[0].x;
			p.clear();
			p.push_back (make_pair (lo, M));
		}
		
		int nr = cr;
		while (nr < N && r[nr].x == r[cr].x)
			nr++;
		
		np.clear();
		int last = 1, cp = 0, end;
		for (int i = cr; i <= nr; i++)
		{
			end = ((i < nr) ? r[i].y : M + 1);
			while (cp < p.size() && p[cp].y < last)
				cp++;
			if (cp < p.size() && max (last, p[cp].x) < end)
				np.push_back (make_pair (max (last, p[cp].x), end - 1));
			last = r[i].y + 1;
		}
		
		p = np;
		lx = r[cr].x;
		cr = nr;
	}
	
	if (p.size() && (lx < M || p[p.size()-1].y == M))
		cout << 2 * M - 2  << "\n";
	else
		cout << "-1\n";
	return 0;
}