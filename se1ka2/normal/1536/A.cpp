#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool f = false;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a < 0) f = true;
        }
        if(f) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << 300 << endl;
            for(int i = 0; i < 300; i++) cout << i << " ";
            cout << endl;
        }
    }
}