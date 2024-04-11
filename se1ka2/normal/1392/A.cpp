#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        bool f = true;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1; i < n; i++){
            if(a[i] != a[i - 1]) f = false;
        }
        if(f) cout << n << endl;
        else cout << 1 << endl;
    }
}