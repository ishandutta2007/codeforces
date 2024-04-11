#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int n, m;
ll x, y;
pair <ll, int> des[MAXN];
pair <ll, int> vest[MAXN];
vector <pair <int, int> > ans;

int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> des[i].first;
        des[i].second = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> vest[i].first;
        vest[i].second = i;
    }
    sort (des, des + n);
    sort (vest, vest + m);
    int dcur = 0, vcur = 0;
    while (dcur < n && vcur < m)
    {
        if (des[dcur].first < vest[vcur].first - y)
            dcur++;
        else if (des[dcur].first > vest[vcur].first + x)
            vcur++;
        else
        {
            ans.push_back (make_pair (des[dcur].second, vest[vcur].second));
            dcur++;
            vcur++;
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
    //system ("Pause");
    return 0;
}