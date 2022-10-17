#include <iostream>
using namespace std;

int A, B, C, D;

int main(){
    cin >> A >> B >> C >> D;

    if((A <= C && B <= D) || (A+B <= max(C, D)))
        cout << "Polycarp" << endl;
    
    else cout << "Vasiliy" << endl;
}