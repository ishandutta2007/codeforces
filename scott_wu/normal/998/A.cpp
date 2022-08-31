#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N;
int arr[12];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    int tot = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        tot += arr[i];
    }
    if (N == 1 || ((tot == 2 * arr[0]) && (tot == 2 * arr[1])))
        cout << "-1\n";
    else
    {
        if (tot != 2 * arr[0])
            cout << "1\n1\n";
        else
            cout << "1\n2\n";
    }
}