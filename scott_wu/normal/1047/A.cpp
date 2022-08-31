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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    if (N % 3 == 2)
        cout << "1 2 " << N - 3 << "\n";
    else
        cout << "1 1 " << N - 2 << "\n";
}