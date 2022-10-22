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
        int a[200005];
        for(int i = 0; i < n * 2; i++) cin >> a[i];
        sort(a, a + n * 2);
        cout << a[n] - a[n - 1] << endl;
    }
}