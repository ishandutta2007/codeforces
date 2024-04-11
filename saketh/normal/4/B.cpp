#include <iostream>
using namespace std;

int D, S, l[32], h[32], L, H;

int main(){
    cin >> D >> S;
    for(int i=0; i<D; i++){
        cin >> l[i] >> h[i];
        L += l[i];
        H += h[i];
    }

    if(L > S || H < S){ cout << "NO" << endl; return 0; }
    cout << "YES\n";

    int ex = S - L;
    for(int i=0; i<D; i++){
        int tv = l[i] + min(ex, h[i]-l[i]);
        cout << tv << " ";
        ex -= tv - l[i];
    }

    cout << endl;
    return 0;
}