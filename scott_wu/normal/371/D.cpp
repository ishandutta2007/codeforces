#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll arr[MAXN];
ll init[MAXN];

int parent[MAXN];
int end[MAXN];
int rank[MAXN];

int find (int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find (parent[x]);
}

void uni (int a, int b)
{
	a = find (a), b = find (b);
	if (a == b) return;
	
	if (rank[a] < rank[b])
		swap (a, b);
	
	rank[a]++;
	parent[b] = a;
	end[a] = max (end[a], end[b]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		parent[i] = end[i] = i;
		
		cin >> arr[i];
		init[i] = arr[i];
	}
	parent[N] = N;
	end[N] = N;
	end[N+1] = N + 1;
	arr[N] = arr[N+1] = 1e18;
	
	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		int t; cin >> t;
		
		if (t == 1)
		{
			int p, x;
			cin >> p >> x;
			p--;
			
			p = end[find (p)];
			while (x >= arr[p])
			{
				if (p >= N) break;
				//cout << p << "\n";
				
				x -= arr[p];
				arr[p] = 0;
				uni (p, p+1);
				
				p = end[find (p)];
			}
			arr[p] -= x;
		}
		else
		{
			int x; cin >> x;
			x--;
			
			cout << init[x] - arr[x] << "\n";
		}
	}
	return 0;
}