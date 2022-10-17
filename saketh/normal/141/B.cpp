#include <iostream>
using namespace std;

int A, X, Y;

bool ins(int cx, int cy){
    if(X <= cx || X >= cx+A) return false;
    if(Y <= cy || Y >= cy+A) return false;
    return true;
}

int main(){
    cin >> A >> X >> Y;
    A *= 2;
    X *= 2;
    Y *= 2;

    if( Y % A == 0) {
        cout << -1 << endl;
        return 0;
    }
    int lv = Y / A;

    if(lv == 0 || lv % 2 == 1){
        if(ins(-A/2, lv * A)) {
            if(lv == 0) cout << 1 << endl;
            else cout << (3 * lv + 1) / 2 << endl;
            return 0;
        }
    }
    else{
        int num = 3 * lv / 2;
        if(ins(-A, lv * A)){
            cout << num << endl;
            return 0;
        }
        else if(ins(0, lv * A)){
            cout << num + 1 << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
}