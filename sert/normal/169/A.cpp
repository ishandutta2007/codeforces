#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, d[3000];
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
      cin >> d[i];
    sort(d, d + n);
    cout << d[b] - d[b - 1];
    return 0;
}