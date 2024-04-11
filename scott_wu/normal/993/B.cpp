#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M;
pair <int, int> a[100], b[100];

int gget (int i, int j)
{
    if (a[i].first == b[j].first)
    {
        if (a[i].second != b[j].second) return a[i].first;
        return 0;
    }
    if (a[i].second == b[j].first)
    {
        if (a[i].first != b[j].second) return a[i].second;
        return 0;
    }
    if (a[i].second == b[j].second)
        return a[i].second;
    if (a[i].first == b[j].second)
        return a[i].first;
    return 0;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < M; i++)
        cin >> b[i].first >> b[i].second;

    int bfound = -1; bool ggood = true;
    bool good = true;
    for (int i = 0; i < N; i++)
    {
        int nmesh = -1;
        for (int j = 0; j < M; j++)
        {
            int x = gget(i, j);
            if (!x) continue;
            if (nmesh == -1)
                nmesh = x;
            if (nmesh != x)
            {
                good = false;
            }
            if (bfound == -1)
                bfound = x;
            if (bfound != x)
            {
                ggood = false;
            }
        }
    }

    for (int j = 0; j < M; j++)
    {
        int nmesh = -1;
        for (int i = 0; i < N; i++)
        {
            int x = gget(i, j);
            if (!x) continue;
            if (nmesh == -1)
                nmesh = x;
            if (nmesh != x)
            {
                good = false;
            }            
        }
    }

    if (ggood)
    {
        cout << bfound << "\n";
    }
    else if (good)
    {
        cout << "0\n";
    }
    else cout << "-1\n";
}