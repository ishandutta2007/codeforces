#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXK = 3000;

int N;
int num[MAXK];
int tot[MAXK];
int ans;

void solve (int cloc, int cdep)
{
    if (cdep == N)
    {
        tot[cloc] = num[cloc];
        return;
    }
    
    solve (cloc * 2, cdep + 1);
    solve (cloc * 2 + 1, cdep + 1);
    
    int x = tot[cloc*2], y = tot[cloc*2+1];
    if (x > y)
        swap (x, y);
    ans += y - x;
    tot[cloc] = y + num[cloc];
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 2; i < (1 << (N + 1)); i++)
        cin >> num[i];
    
    ans = 0;
    solve (1, 0);
    cout << ans << "\n";
    return 0;
}