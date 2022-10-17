#include <iostream>
using namespace std;

typedef long long ll;

ll A, B, D, r;

int main(){
    cin >> A >> B;
    if(A<=B){
        cout << (A==B?"infinity":"0") << endl;
        return 0;
    }
    D = A-B;

    for(ll i=1; i*i<=D; i++){
        if(D%i) continue;
        if(i>B) r++;
        if(i*i!=D && (D/i>B)) r++; 
    } 
    cout << r << endl;
}