#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;

int N, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    cout << (N + 2 * K) / (2 * K + 1) << "\n";
    if ((N + 2 * K) % (2 * K + 1) < K)
    {
        for (int i = 1; i <= N; i += 2 * K + 1)
            cout << i << " ";
    }
    else
    {
        for (int i = K + 1; i <= N; i += 2 * K + 1)
            cout << i << " ";
    }
}