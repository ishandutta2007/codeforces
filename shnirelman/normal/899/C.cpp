#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n % 4 == 0){
        cout << 0 << endl << (n / 2) << ' ';

        for(int i = 1; i < n; ){
            cout << i << ' ' << i + 3 << ' ';
            i += 4;
        }
    }
    else if(n % 4 == 2){
        cout << 1 << endl << (n / 2) << ' ' << 1 << ' ';

        for(int i = 3; i < n; ){
            cout << i << ' ' << (i + 3) << ' ';
            i += 4;
        }
    }
    else if(n % 4 == 3){
        cout << 0 << endl << (n / 2) << ' ' << 3 << ' ';

        for(int i = 4; i < n; ){
            cout << i << ' ' << (i + 3) << ' ';
            i += 4;
        }
    }
    else{
        cout << 1 << endl << (n / 2 + 1) << ' ' << 1 << ' ';

        for(int i = 2; i < n; ){
            cout << i << ' ' << (i + 3) << ' ';
            i += 4;
        }
    }
}