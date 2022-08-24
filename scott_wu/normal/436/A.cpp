#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, X;
int nuse[2];
pair <int, int> candy[2][MAXN];
bool use[2][MAXN];

inline bool cmp (pair <int, int> left, pair <int, int> right)
{
    return left.second > right.second;
}

int run()
{
    int ans = 0, cloc = 0;
    int cmass = X;
    
    while (true)
    {
        bool flag = false;
        for (int i = 0; i < nuse[cloc]; i++)
        {
            if (candy[cloc][i].first <= cmass && !use[cloc][i])
            {
                ans++;
                cmass += candy[cloc][i].second;
                use[cloc][i] = flag = true;
                cloc = 1 - cloc;
                break;
            }
        }
        
        if (!flag) break;
    }
    return ans;
}

int main()
{
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        candy[a][nuse[a]++] = make_pair (b, c);
    }
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < MAXN; j++)
            use[i][j] = false;
    
    for (int i = 0; i < 2; i++)
        sort (candy[i], candy[i] + nuse[i], cmp);
    
    int res = run();
    
    swap (nuse[0], nuse[1]);
    for (int i = 0; i < MAXN; i++)
    {
        swap (candy[0][i], candy[1][i]);
        use[0][i] = use[1][i] = false;
    }
    
    res = max (res, run());
    cout << res << "\n";
    
    //system ("Pause");
    return 0;
}