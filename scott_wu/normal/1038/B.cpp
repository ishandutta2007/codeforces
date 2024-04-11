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

int main()
{
    ios_base::sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 2; i <= N; i++)
    {
        int v = N * (N + 1) / 2;
        if (v % i == 0)
        {
            cout << "Yes\n";
            cout << "1 " << i << "\n";
            cout << N - 1;
            for (int j = 1; j <= N; j++)
                if (j != i) cout << " " << j;
            cout << "\n";
            return 0;
        }
    }
    cout << "No\n";
}