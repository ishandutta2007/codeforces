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
const int MAXN = 300100;
const int MAXP = 16e6;

int N;
int arr[MAXN];
int pp[MAXP];

map <int, int> plist;

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

int main()
{
    for (int i = 2; i < MAXP; i += 2)
        pp[i] = 2;
    for (int i = 3; i < MAXP; i += 2)
    {
        if (pp[i] == 0)
        {
            pp[i] = i;
            if (MAXP / i >= i)
            {
                for (int j = i * i; j < MAXP; j += i)
                    pp[j] = i;
            }
        }
    }

    int g = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        g = gcd (g, arr[i]);
    }

    bool found = false;
    for (int i = 0; i < N; i++)
    {
        arr[i] /= g;
        if (arr[i] > 1)
            found = true;
    }

    if (!found)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int cc = arr[i];
        while (cc > 1)
        {
            int pt = pp[cc];
            while (cc % pt == 0)
            {
                cc /= pt;
            }
            plist[pt]++;
        }
    }

    int ans = N;
    for (pair <int, int> cp : plist)
        ans = min (ans, N - cp.second);
    cout << ans << "\n";
}