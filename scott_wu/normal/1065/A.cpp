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
    for (int test = 0; test < T; test++)
    {
        ll S, A, B, C;
        cin >> S >> A >> B >> C;
        cout << S / (A * C) * B + S / C << "\n";
    }
}