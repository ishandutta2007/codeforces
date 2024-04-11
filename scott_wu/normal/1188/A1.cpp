#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int deg[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        deg[i] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        deg[x]++;
        deg[y]++;
    }

    bool found = false;
    for (int i = 0; i < N; i++)
        if (deg[i] == 2)
            found = true;

    if (found)
        cout << "NO\n";
    else
        cout << "YES\n";
}