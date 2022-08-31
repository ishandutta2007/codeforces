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
int arr[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 1; i < N - 1; i++)
        if (!arr[i] && arr[i-1] && arr[i+1])
        {
            arr[i+1] = 0;
            ans++;
        }
    cout << ans << "\n";
}