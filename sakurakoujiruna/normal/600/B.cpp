#include <iostream>
#include <map>
using namespace std;

const int N = 401111;
int a[N];
int b[N];
int pre[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map <int, int> disc;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		disc[a[i]] = 1;
	}
	for(int i = 0; i < m; i ++)
	{
		cin >> b[i];
		disc[b[i]] = 1;
	}
	int disc_cnt = 0;
	for(auto it = disc.begin(); it != disc.end(); it ++)
		disc[it -> first] = disc_cnt ++;
	for(int i = 0; i < n; i ++)
		pre[disc[a[i]]] ++;
	for(int i = 1; i < N; i ++)
		pre[i] += pre[i - 1];
	for(int i = 0; i < m; i ++)
		cout << pre[disc[b[i]]] << ' ';
	cout << '\n';
	return 0;
}