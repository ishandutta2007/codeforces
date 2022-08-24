#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;

vector <int> figure (int N)
{
    vector <int> res;
    if (N <= 3)
    {
        for (int i = 0; i < N - 1; i++)
            res.push_back(1);
        res.push_back(N);
        return res;
    }

    int nodd = N - N / 2;
    for (int i = 0; i < nodd; i++)
        res.push_back(1);
    vector <int> vres = figure (N / 2);
    for (int x : vres)
        res.push_back (2 * x);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int N; cin >> N;

    vector <int> v = figure (N);
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}