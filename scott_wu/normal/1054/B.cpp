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
    int N; cin >> N;

    int cm = 0;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (x > cm)
        {
            cout << i + 1 << "\n";
            return 0;
        }
        else if (x == cm)
        {
            cm++;
        }
    }
    cout << "-1\n";
}