#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
int arr[110];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    cin >> T;
    
    sort (arr, arr + N);
    
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (arr[j] - arr[i] <= T)
                ans = max (ans, j - i + 1);
    cout << ans << "\n";
    return 0;
}