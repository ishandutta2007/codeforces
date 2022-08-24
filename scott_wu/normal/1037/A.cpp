#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= 30; i++)
    {
        if ((1 << i) - 1 >= N)
        {
            cout << i << "\n";
            return 0;
        }
    }
}