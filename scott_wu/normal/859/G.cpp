#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int v[MAXN];

int M;
vector <int> primes;

int arr[MAXN];

bool solve() // M, arr
{
    for (int i = 0; i < M; i++)
    {
        int tot = 0;
        for (int j = 0; j < (1 << primes.size()); j++)
        {
            int cc = 0, cscore = 0;
            for (int k = 0; k < primes.size(); k++)
            {
                if (j & (1 << k))
                {
                    cc++;
                    cscore += M / primes[k] * (i % primes[k]);
                }
            }
            cscore %= M;

            //cout << i << " " << j << " " << arr[cscore] << " " << cscore << "\n";
            if (cc % 2 == 0)
                tot += arr[cscore];
            else
                tot -= arr[cscore];
        }
        if (tot != 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char ch; cin >> ch;
        v[i] = ch - '0';
    }

    primes.clear();

    M = 1;
    int tn = N;
    for (int i = 2; i <= N; i++)
    {
        if (tn % i == 0)
        {
            primes.push_back (i);
            M *= i;
        }
        while (tn % i == 0)
            tn /= i;
    }

    int ndiff = N / M;
    bool works = true;
    for (int i = 0; i < ndiff; i++)
    {
        for (int j = i; j < N; j += ndiff)
            arr[j / ndiff] = v[j];

        if (!solve())
            works = false;
    }

    if (works)
        cout << "YES\n";
    else
        cout << "NO\n";
}