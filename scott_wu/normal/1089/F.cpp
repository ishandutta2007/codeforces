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

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N; cin >> N;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            if (gcd (i, N / i) == 1)
            {
                int r = N - 1;
                for (int j = 0; j <= i; j++)
                    if ((r - (j * (N / i))) % i == 0)
                    {
                        int nc = (r - (j * (N / i))) / i;
                        cout << "YES\n2\n";
                        cout << j << " " << i << "\n";
                        cout << nc << " " << N / i << "\n";
                        return 0;
                    }
            }
        }
    }
    cout << "NO\n";
}