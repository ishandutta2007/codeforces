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

int N;
int d[100100];
vector <int> l, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y; cin >> x >> y;
        d[x]++;
        d[y]++;
    }

    for (int i = 1; i <= N; i++)
        if (d[i] == 1)
            l.push_back(i);
        else if (d[i] > 2)
            r.push_back(i);

    if (r.size() >= 2)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    if (r.size() == 0)
    {
        cout << "1\n";
        cout << l[0] << " " << l[1] << "\n";
        return 0;
    }
    cout << l.size() << "\n";
    for (int i = 0; i < l.size(); i++)
        cout << l[i] << " " << r[0] << "\n";
}