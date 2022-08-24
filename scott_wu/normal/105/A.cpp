#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
    string name;
    int val;
};

inline bool operator < (point a, point b)
{
    return a.name < b.name;
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    double temp;
    cin >> temp;
    k = temp * 100.0 + 0.1;
    string cur[25];
    int val[25];
    for (int a = 0; a < n; a++)
        cin >> cur[a] >> val[a];
    string next[25];
    for (int a = 0; a < m; a++)
        cin >> next[a];
    bool use[25];
    for (int a = 0; a < n; a++)
        val[a] *= k;
    for (int a = 0; a < 25; a++)
        use[a] = true;
    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (next[a] == cur[b])
                if (val[b] >= 10000)
                    use[a] = false;
        }
    }
    vector <point> ans;
    for (int a = 0; a < n; a++)
    {
        if (val[a] >= 10000)
        {
            point temp2;
            temp2.name = cur[a];
            temp2.val = val[a] / 100;
            ans.push_back (temp2);
        }
    }
    for (int a = 0; a < m; a++)
    {
        if (use[a])
        {
            point temp3;
            temp3.name = next[a];
            temp3.val = 0;
            ans.push_back (temp3);
        }
    }
    sort (ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int a = 0; a < ans.size(); a++)
        cout << ans[a].name << " " << ans[a].val << "\n";
    return 0;
}