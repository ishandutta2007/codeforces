#include <algorithm>
#include <iostream>
using namespace std;

bool lucky(int arg){
    arg = abs(arg);
    while(arg){
        if(arg%10 == 8) return true;
        arg/=10;
    }
    return false;
}

int main(){
    int A; cin >> A;
    for(int i=1; ; i++){
        if(lucky(A+i)){
            cout << i << endl;
            return 0;
        }
    }
}