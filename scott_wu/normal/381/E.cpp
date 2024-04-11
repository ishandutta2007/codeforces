#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int MAXP = 4000100;
const int P = (1 << 20);

int N, M;
bool b[MAXN];
string s;

int ps[MAXN];
int seg[MAXP];


int lo (int cloc, int start, int end, int l, int r)
{
	if (l <= start && end <= r)
		return seg[cloc];
	if (l > end || r < start)
		return 1e9;
	int mid = (start + end) / 2;
	return min (lo (2 * cloc, start, mid, l, r), lo (2 * cloc + 1, mid + 1, end, l, r));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s;
	
	N = s.length();
	for (int i = 0; i < N; i++)
		b[i] = (s[i] == '(');
	
	ps[0] = 0;
	for (int i = 0; i < N; i++)
		ps[i+1] = ps[i] + ((b[i]) ? 1 : - 1);
	
	for (int i = 0; i < 2 * P; i++)
		seg[i] = 1e9;
	for (int i = P; i < P + N; i++)
		seg[i] = ps[i-P];
	for (int i = P - 1; i >= 1; i--)
		seg[i] = min (seg[2*i], seg[2*i+1]);
	
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		int a = ps[l], b = ps[r+1], c = lo (1, 0, P - 1, l, r + 1);
		int res = 0;
		if (c < a)
		{
			res = a - c;
			b += a - c;
		}
		res += abs (a - b);
		cout << (r - l + 1) - res << "\n";
	}
	return 0;
}