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

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M, L, R;
        cin >> N >> M >> L >> R;
        cout << (L - 1) / M + N / M - R / M << "\n";
    }
}