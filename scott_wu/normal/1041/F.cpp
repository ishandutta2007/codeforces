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
const int MAXN = 200100;

int N, M, Y, Y2;
int A[MAXN], B[MAXN];
map <int, int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> Y;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M >> Y2;
    for (int i = 0; i < M; i++)
        cin >> B[i];

    int v = 1;
    int ans = 0;
    for (int p2 = 0; p2 <= 30; p2++)
    {
        m.clear();
        int v2 = v * 2;
        if (p2 == 30)
            v2 = v;
        for (int i = 0; i < N; i++)
        {
            m[A[i] % v2]++;
        }
        for (int i = 0; i < M; i++)
        {
            m[(B[i] + v) % v2]++;
        }

        for (auto it : m)
            ans = max (ans, it.second);
        v = v2;
    }
    cout << ans << "\n";
}