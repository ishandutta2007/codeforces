#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[1002];
        bool f[2]{0};
        int s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
            f[a[i] % 2] = true;
        }
        if(x == n){
            if(s % 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if(!f[1]) cout << "No" << endl;
        else if(!f[0]){
            if(x % 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
}