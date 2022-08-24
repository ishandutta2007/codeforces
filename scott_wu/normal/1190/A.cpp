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

ll N, K;
int M;
ll p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    int ans = 0;
    int cloc = 0;
    while (cloc < M)
    {
        int nloc = cloc;
        ll cv = (p[cloc] - cloc) / K;
        while (cloc < M && cv == (p[cloc] - nloc) / K)
            cloc++;
        ans++;
    }
    cout << ans << "\n";
}