#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[52], b[52];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        bool f = true;
        for(int i = 0; i < n; i++){
            if(a[i] + b[i] > x) f = false;
        }
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}