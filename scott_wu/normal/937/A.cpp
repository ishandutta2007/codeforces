#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    arr[N] = 0;
    sort (arr, arr + N + 1);

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] > 0 && arr[i] != arr[i-1])
            ans++;
    }
    cout << ans << "\n";
}