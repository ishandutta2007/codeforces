#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100011;
const int M = 3011111;
typedef long long intl;

const int Block = 310;
struct Query
{
	int left, right;
	int id;
	Query() { }
	Query(int left, int right, int id) : left(left), right(right), id(id) { }
	bool operator <(const Query &rhs) const
	{
		if(left / Block == rhs.left / Block)
			return right < rhs.right;
		return left < rhs.left;
	}
}query[N];

int a[N];
int cnt[M];
intl ans[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		a[i] ^= a[i - 1];
	}
	for(int i = 0; i < m; i ++)
	{
		cin >> query[i].left;
		cin >> query[i].right;
		query[i].left --;
		query[i].right ++;
		query[i].id = i;
	}
	sort(query, query + m);

	intl acc = 0;
	int left = 0, right = 0;
	for(int i = 0; i < m; i ++)
	{
		Query &q = query[i];
		while(right < q.right)
		{
			acc += cnt[a[right] ^ k];
			cnt[a[right]] ++;
			right ++;
		}
		while(left > q.left)
		{
			left --;
			acc += cnt[a[left] ^ k];
			cnt[a[left]] ++;
		}
		while(right > q.right)
		{
			right --;
			cnt[a[right]] --;
			acc -= cnt[a[right] ^ k];
		}
		while(left < q.left)
		{
			cnt[a[left]] --;
			acc -= cnt[a[left] ^ k];
			left ++;
		}
		ans[q.id] = acc;
	}
	for(int i = 0; i < m; i ++)
		cout << ans[i] << '\n';
	return 0;
}