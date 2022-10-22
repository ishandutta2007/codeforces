#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int a[100002];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<int>());
        cout << min(a[1] - 1, n - 2) << endl;
    }
}