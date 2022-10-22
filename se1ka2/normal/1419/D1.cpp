#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    cout << (n - 1) / 2 << endl;
    for(int i = 0; i < n; i++){
        if(i % 2) cout << a[n - i / 2 - 1] << " ";
        else cout << a[i / 2] << " ";
    }
    cout << endl;
}