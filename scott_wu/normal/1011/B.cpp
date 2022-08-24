#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
int nc[MAXN];

bool works (int cloc)
{
    int r = 0;
    for (int i = 0; i < MAXN; i++)
        r += nc[i] / cloc;
    return r >= N;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x; cin >> x;
        nc[x]++;
    }

    int cloc = 1;
    while (works (cloc))
        cloc++;
    cout << cloc - 1 << "\n";
}