#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue <pair <int, pair<int, int> > > q;
int n, x, m;
int d[100100];
int k[100100];

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        d[i] = -(2 * abs((i * 2) - n + 1) + (i * 2) / n);
    for (int i = 0; i < n; i++)
        q.push(make_pair(0, make_pair(d[i], i)));
    for (int i = 0; i < m; i++) {
        x = q.top().second.second;
        k[x]++;
        cout << x + 1 << "\n";
        q.pop();
        q.push(make_pair(-k[x], make_pair(d[x], x)));
    }
    return 0;
}