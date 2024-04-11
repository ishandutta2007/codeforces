#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[52];
        for(int i = 0; i < n; i++) cin >> a[i];
        if(is_sorted(a, a + n)) cout << 0 << endl;
        else if(a[0] == 1 || a[n - 1] == n) cout << 1 << endl;
        else if(a[0] != n || a[n - 1] != 1) cout << 2 << endl;
        else cout << 3 << endl;
    }
}