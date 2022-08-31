#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N, K;
map <int, int> mc;

vector <int> get_run (int x)
{
    vector <int> ans;
    for (pair <int, int> pp : mc)
    {
        int nc = pp.second / x;
        for (int i = 0; i < nc; i++)
            ans.push_back(pp.first);
    }
    return ans;
}

bool works (int x)
{
    return get_run(x).size() >= K;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int t; cin >> t;
        mc[t]++;
    }

    int lo = 1, hi = N;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (works (mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    vector <int> v = get_run (lo);
    for (int i = 0; i < K; i++)
    {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}