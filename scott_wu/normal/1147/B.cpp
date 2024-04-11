#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M;
pair <int, int> v[MAXN];
pair <int, int> nv[MAXN];

bool prime[MAXN];

bool test (int x)
{
    for (int i = 0; i < M; i++)
    {
        nv[i].first = (v[i].first + x) % N;
        nv[i].second = (v[i].second + x) % N;
        if (nv[i].first > nv[i].second)
            swap (nv[i].first, nv[i].second);
    }
    sort (nv, nv + M);
    for (int i = 0; i < M; i++)
    {
        if (v[i] != nv[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first = v[i].first % N;
        v[i].second = v[i].second % N;
        if (v[i].first > v[i].second)
            swap (v[i].first, v[i].second);
    }
    sort (v, v + M);

    for (int i = 0; i < MAXN; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXN; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j < MAXN; j += i)
                prime[j] = false;
        }
    }

    for (int i = 2; i < MAXN; i++)
    {
        if (prime[i] && (N % i == 0))
        {
            if (test (N / i))
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}