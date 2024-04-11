#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef unsigned long long ll;
const int MAXD = (1 << 21);

int N;
string A, B;
ll l[MAXD], r[MAXD], tot[MAXD];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> A >> B;
    for (int i = 0; i < (1 << N); i++)
    {
        l[i] = A[i] - '0';
        r[i] = B[i] - '0';
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            if (!(j & (1 << i)))
            {
                l[j+(1<<i)] = 4 * l[j+(1<<i)] + l[j];
                r[j+(1<<i)] = 4 * r[j+(1<<i)] + r[j];
            }
        }
    }
    for (int i = 0; i < (1 << N); i++)
        tot[i] = l[i] * r[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            if (!(j & (1 << i)))
            {
                tot[j+(1<<i)] -= tot[j];
            }
        }
    }
    
    for (int i = 0; i < (1 << N); i++)
    {
        char res = '0' + ((tot[i] >> (2 * __builtin_popcount(i))) & 3);
        cout << res;
    }
    cout << "\n";
}