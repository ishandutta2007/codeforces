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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            if (N / i < K)
            {
                cout << i * K + N / i << "\n";
                return 0;
            }
    }
}