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

int N, K, L;
int arr[100100];

int main()
{
    cin >> N >> K >> L;
    for (int i = 0; i < N * K; i++)
        cin >> arr[i];
    sort (arr, arr + N * K);
    int cloc = 0;
    while (cloc < N * K && arr[cloc] <= arr[0] + L)
        cloc++;
    cloc--;
    
    if (cloc < N - 1)
        cout << "0\n";
    else
    {
        long long res = 0;
        for (int i = 0; i < N; i++)
            res += min (arr[i*K], arr[cloc-N+1+i]);
        cout << res << "\n";
    }
}