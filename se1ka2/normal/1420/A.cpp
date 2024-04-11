#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[50005];
        for(int i = 0; i < n; i++) cin >> a[i];
        bool f = false;
        for(int i = 0; i < n - 1; i++){
            if(a[i] <= a[i + 1]) f = true;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}