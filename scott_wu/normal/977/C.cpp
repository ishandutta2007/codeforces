#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, K;
int arr[MAXN];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    if (K == 0)
    {
        if (arr[0] == 1)
            cout << "-1\n";
        else
            cout << "1\n";
        return 0;
    }

    if (arr[K] != arr[K-1])
        cout << arr[K-1] << "\n";
    else
        cout << "-1\n";
}