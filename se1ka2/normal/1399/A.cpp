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
        sort(a, a + n);
        bool f = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i] < a[i + 1] - 1) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}