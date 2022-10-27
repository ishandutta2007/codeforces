#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, w[102];
vector<int> v;
int main()
{
    int res = 1000000000;
    cin >> n; n *= 2;

    for (int i = 1; i <= n; i ++) cin >> w[i];
    
    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            v.clear();

            for (int k = 1; k <= n; k ++)
            {
                if (k == i || k == j) continue;
                v.push_back(w[k]);
            }

            sort(v.begin(), v.end());

            int ans = 0;
            for (int i = 1; i < v.size(); i += 2)
            {
                ans += v[i] - v[i-1];
            }
            res = min(res, ans);

            //printf("%d %d\n", i, j);
        }
    }
    cout << res << endl;
}