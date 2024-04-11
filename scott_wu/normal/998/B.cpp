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

int N, B;
int arr[100];
vector <int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int nc = 0;
    for (int i = 0; i < N - 1; i++)
    {
        nc += 2 * (arr[i] % 2) - 1;
        if (nc == 0)
            v.push_back(abs(arr[i] - arr[i+1]));
    }
    sort (v.begin(), v.end());

    int res = 0;
    while (res < v.size() && B >= v[res])
    {
        B -= v[res];
        res++;
    }
    cout << res << "\n";
}