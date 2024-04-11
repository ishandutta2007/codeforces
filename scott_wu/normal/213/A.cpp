#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 210;

int N;
vector <int> edge[MAXN];
int deg[MAXN];
int comp[MAXN];
bool seen[MAXN];
int ndeg[MAXN];

int solve (int cstart)
{
    int res = 0, ccomp = cstart;
    
    for (int i = 0; i < N; i++)
    {
        seen[i] = false;
        ndeg[i] = deg[i];
    }
    
    int nleft = N;
    while (nleft > 0)
    {
        bool check = true;
        int loc = -1;
        
        for (int i = 0; i < N; i++)
            if (!seen[i] && ndeg[i] <= 0 && comp[i] == ccomp)
            {
                check = false;
                loc = i;
            }
        
        if (check)
        {
            res++;
            ccomp = (ccomp + 1) % 3;
            continue;
        }
        
        //cout << loc << "\n";
        res++;
        nleft--;
        seen[loc] = true;
        for (int i = 0; i < edge[loc].size(); i++)
            ndeg[edge[loc][i]]--;
    }
    return res;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> comp[i];
        comp[i]--;
    }
    
    for (int i = 0; i < N; i++)
    {
        cin >> deg[i];
        for (int j = 0; j < deg[i]; j++)
        {
            int t;
            cin >> t;
            t--;
            edge[t].push_back (i);
        }
    }
    
    int ans = min (solve (0), min (solve (1), solve (2)));
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}