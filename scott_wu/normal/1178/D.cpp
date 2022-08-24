#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;

int N;
vector <pair <int, int> > res;

bool is_prime (int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        res.push_back(make_pair (i, (i + 1) % N));
    }

    int M = N;
    while (!is_prime (M))
        M++;

    for (int i = 0; i < M - N; i++)
    {
        res.push_back(make_pair (i, (i + N/2) % N));
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first + 1 << " " << res[i].second + 1 << "\n";
    }
}