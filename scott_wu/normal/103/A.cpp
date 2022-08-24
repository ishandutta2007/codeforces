#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long num[110];
    for (long long a = 0; a < n; a++)
        cin >> num[a];
    long long sum = 0;
    long long ans = 0;
    for (long long a = 0; a < n; a++)
        ans += (num[a] - 1) * (a + 1) + 1;
    cout << ans << "\n";
    return 0;
}