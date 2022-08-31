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

int N;

vector <pair <int, int> > v;

void fput (int x, int y)
{
    cout << (char) ('a' + x) << (1 + y) << " ";
}

void gs()
{
    for (int i = 0; i < v.size(); i++)
        if (v[i].second >= 6)
            v[i].second = 13 - v[i].second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int y = j;
            if (i % 2 == 1)
                y = 7 - j;
            v.push_back (make_pair (i, y));
        }
    }

    if (N >= 58)
    {
        gs();
        for (int i = 0; i < 57; i++)
            fput (v[i].first, v[i].second);
        for (int i = 57; i < N; i++)
            fput (7, i - 57);
        cout << "h8\n";
        return 0;
    }
    if (v[N-2].second == 7)
        gs();
    for (int i = 0; i <= N - 2; i++)
        fput (v[i].first, v[i].second);
    fput (7, v[N-2].second);
    cout << "h8\n";
}