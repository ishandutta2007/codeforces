#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

vector <pair <int, int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    
    sort (v.begin(), v.end());
    long long res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i + 1 < v.size() && v[i+1].first == v[i].first)
            continue;
        res += v[i].second;
    }
    cout << res << "\n";
}