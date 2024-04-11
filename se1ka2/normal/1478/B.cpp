#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int q, d;
        cin >> q >> d;
        while(q--){
            int a;
            cin >> a;
            if(a >= d * 10){
                cout << "YES" << endl;
                continue;
            }
            bool f = false;
            int c = 0;
            for(int i = 0; i < 10; i++){
                c += d;
                if(c > a) break;
                if(c % 10 == a % 10) f = true;
            }
            if(f) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}