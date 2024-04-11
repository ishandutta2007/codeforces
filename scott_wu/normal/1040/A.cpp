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

int N, A, B;
int arr[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int res = 0;
    bool bad = false;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] + arr[N-1-i] == 1)
            bad = true;
        else if (arr[i] + arr[N-1-i] == 4)
        {
            arr[i] = arr[N-1-i] = 0;
            res += 2 * min (A, B);
            if (i * 2 == N - 1)
                res -= min (A, B);
        }
        else if (arr[i] == 2)
        {
            if (arr[N-1-i] == 0)
                res += A;
            else
                res += B;
            arr[i] = arr[N-1-i];
        }
    }
    if (bad) cout << "-1\n";
    else cout << res << "\n";
}