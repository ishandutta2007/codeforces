#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[30005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int c = 0;
        bool f = true;
        for(int i = n - 2; i >= 0; i--){
            if(a[i] < c){
                f = false;
                break;
            }
            if(a[i] > a[i + 1]) c += a[i] - a[i + 1];
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}