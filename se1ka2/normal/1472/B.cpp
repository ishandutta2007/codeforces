#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[102];
        int s = 0;
        bool f = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
            if(a[i] == 1) f = true;
        }
        if(s % 2) cout << "NO" << endl;
        else if(s % 4){
            if(n % 2 && !f) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else cout << "YES" << endl;
    }
}