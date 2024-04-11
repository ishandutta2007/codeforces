#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <complex>
#include <fstream>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;

const int maxn = 1024;

int calc_max(vector<int> &v)
{
    int res = -1;
    for (int i = 0; i < maxn; ++i)
        if (v[i] > 0)
            res = i;
    return res;
}

int calc_min(vector<int> &v)
{
    int res = -1;
    for (int i = 0; i < maxn; ++i)
        if (v[i] > 0)
            return i;
    return res;
}

void do_move(vector<int> &v, int x)
{
    int done = 0;
    vector<int> v2(maxn, 0);
    for (int i = 0; i < maxn; ++i)
    {
        if (done & 1)
        {
            done += v[i];
            v2[i ^ x] += v[i] / 2;
            v2[i] += (v[i] + 1) / 2;
        }
        else
        {
            done += v[i];
            v2[i ^ x] += (v[i] + 1) / 2;
            v2[i] += v[i] / 2;
        }
    }
    v = v2;
}

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(maxn, 0);
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        ++arr[v];
    }
    for (int i = 0; i < k; ++i)
        do_move(arr, x);
    cout << calc_max(arr) << " " << calc_min(arr) << endl;
}