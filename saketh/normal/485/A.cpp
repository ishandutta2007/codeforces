#include <iostream>
using namespace std;

int A, M;

int main(){
    cin >> A >> M;
    A %= M;

    for(int i=0; i<100005; i++){
        A = (2 * A) % M;
        if(!A){ cout << "Yes" << endl; return 0; }
    }

    cout << "No" << endl;
    return 0;
}