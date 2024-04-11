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

int N, S;
int a[1100];
int b[1100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    bool good = false;
    S--;
    if (a[0] && a[S])
        good = true;

    for (int i = S; i < N; i++)
    {
        if (a[0] && a[i] && b[i] && b[S])
            good = true;
    }
    if (good) cout << "YES\n";
    else cout << "NO\n";
}