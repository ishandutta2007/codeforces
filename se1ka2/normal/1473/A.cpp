#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        int a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        if(a[0] + a[1] <= d || a[n - 1] <= d) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}