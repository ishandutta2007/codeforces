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
        int s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        sort(a, a + n);
        if(s == 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(s > 0){
            for(int i = n - 1; i >= 0; i--) cout << a[i] << " ";
            cout << endl;
        }
        else{
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }
    }
}