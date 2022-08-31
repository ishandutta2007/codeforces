#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int N;

int get_q (int x)
{
    x = x % N;
    if (x == 0)
        x = N;

    cout << "? " << x << "\n" << flush;
    int v; cin >> v;
    return v;
}

void put_ans (int x)
{
    x = x % N;
    if (x == 0)
        x = N;

    cout << "! " << x << "\n" << flush;
}

int main()
{
    cin >> N;
    if (N % 4 != 0)
    {
        put_ans(-1);
        return 0;
    }

    int l = get_q (1), r = get_q (N / 2 + 1);
    if (l == r)
    {
        put_ans(1);
        return 0;
    }

    int lo, hi;
    if (l < r)
    {
        lo = 1;
        hi = N / 2 + 1;
    }
    else
    {
        lo = N / 2 + 1;
        hi = N + 1;
    }

    while (lo < hi)
    {
        // lo is smaller, hi is bigger
        int mid = (lo + hi) / 2;
        l = get_q (mid);
        r = get_q (mid + N / 2);
        if (l == r)
        {
            put_ans (mid);
            return 0;
        }
        else if (l < r)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    put_ans (lo);
    return 0;
}