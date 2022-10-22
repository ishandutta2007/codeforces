#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[102], b[102];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n, greater<int>());
    sort(b, b + m, greater<int>());
    cout << a[0] << " " << b[0] << endl;
}