// I'm back ...
#include<bits/stdc++.h>
using namespace std;
const int N = 119;
int n, F[N], T[N];
long double D[N];
vector < pair < int , int > > Adj[N];
void DFS(int v, int p)
{
	long double d = 2.0 / Adj[v].size(), t = 1.0;
	for (auto X : Adj[v])
        if (X.first == p)
            t += D[X.second], t -= (t > 2.0) ? 2.0 : 0;
	for (auto X : Adj[v])
		if (X.first != p)
        {
            F[X.second] = v;
            T[X.second] = X.first;
            t += d; t -= (t > 2.0) ? 2 : 0;
            D[X.second] = t;
            DFS(X.first, v);
        }
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
    scanf("%d%d", &F[i], &T[i]), Adj[F[i]].push_back({T[i], i}), Adj[T[i]].push_back({F[i], i});
	DFS(1, 0);
	printf("%d\n", n - 1);
	for (int i = 1; i < n; i++)
    {
        if (D[i] > 1)
            swap(F[i], T[i]), D[i] -= 1;
        printf("1 %d %d %d %.12f\n", i, F[i], T[i], (double)D[i]);
    }
	return 0;
}