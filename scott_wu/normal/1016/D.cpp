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

int N, M;
int a[110], b[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    int xx = 0, yy = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        xx ^= a[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> b[i];
        yy ^= b[i];
    }
    if (xx != yy)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j) cout << " ";
            if (i + j == 0)
                cout << (xx ^ a[0] ^ b[0]);
            else if (j == 0)
                cout << a[i];
            else if (i == 0)
                cout << b[j];
            else
                cout << "0";
        }
        cout << "\n";
    }
}