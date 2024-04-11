#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int n, k;
vector <pair <ll, int> > stool;
vector <pair <ll, int> > pencil;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        ll t, t2;
        cin >> t >> t2;
        if (t2 == 1)
            stool.push_back (make_pair (t, i));
        else
            pencil.push_back (make_pair (t, i));
    }
    sort (stool.begin(), stool.end());
    sort (pencil.begin(), pencil.end());
    ll dis = 0;
    if (stool.size() < k)
    {
        //cout << "blah\n";
        for (int i = 0; i < stool.size(); i++)
            dis += stool[i].first;
    }
    else
    {
        if (pencil.size() > 0)
            dis = min (pencil[0].first, stool[0].first);
        else
            dis = stool[0].first;
        for (int i = stool.size() - k + 1; i < stool.size(); i++)
            dis += stool[i].first;
    }
    ll total = 0;
    for (int i = 0; i < stool.size(); i++)
        total += stool[i].first;
    for (int i = 0; i < pencil.size(); i++)
        total += pencil[i].first;
    double ans = (double) total - ((double) dis) / 2.0;
    cout << fixed << setprecision(1);
    cout << ans << "\n";
    if (stool.size() < k)
    {
        for (int i = 0; i < stool.size(); i++)
            cout << "1 " << stool[i].second + 1 << "\n";
        for (int i = stool.size(); i < k - 1; i++)
            cout << "1 " << pencil[i-stool.size()].second + 1 << "\n";
        cout << n - k + 1;
        for (int i = k - 1; i < n; i++)
            cout << " " << pencil[i-stool.size()].second + 1;
        cout << "\n";
    }
    else
    {
        for (int i = stool.size() - k + 1; i < stool.size(); i++)
            cout << "1 " << stool[i].second + 1 << "\n";
        int v = stool.size() - k + 1 + pencil.size();
        cout << v;
        for (int i = 0; i < pencil.size(); i++)
            cout << " " << pencil[i].second + 1;
        for (int i = 0; i < stool.size() - k + 1; i++)
            cout << " " << stool[i].second + 1;
        cout << "\n";
    }
    //system ("Pause");
    return 0;
}