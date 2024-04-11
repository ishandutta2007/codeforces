#include<iostream>
using namespace std;

int main(){
    int z, o;
    cin >> z >> o;
    
    if(o < z-1 || o > 2*(z+1)){
        cout << -1 << endl;
        return 0;
    }
    
    o -= (z-1);
    if(o){ cout << "1"; o--; }
    for(int i=0; i<z; i++){
        if(o){ cout << "1"; o--; }
        cout << "0";    
        if(i<z-1) cout << "1";
    }
    if(o){ cout << "1"; o--; }
    if(o){ cout << "1"; o--; }
    cout << endl;
    return 0;
}