#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int s = 0;
        int a[102];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        bool f = false;
        for(int i = 2; i < s; i++){
            if(s % i == 0){
                f = true;
                break;
            }
        }
        if(f){
            cout << n << endl;
            for(int i = 0; i < n; i++) cout << i + 1 << " ";
            cout << endl;
        }
        else{
            cout << n - 1 << endl;
            bool g = false;
            for(int i = 0; i < n; i++){
                if(a[i] % 2 && !g) g = true;
                else cout << i + 1 << " ";
            }
            cout << endl;
        }
    }
}