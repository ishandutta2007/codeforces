#include <iostream>
using namespace std;
int main(){
    int k,d;
    cin >> k >> d;
    if(k == 1 && d == 0){
        cout << 0;
        return 0;
    }else if(d == 0){
        cout << "No solution";
        return 0;
    }
    cout << d;
    for(int i = 0; i < k-1; i++){
        cout << 0;
    }
    cout << endl;
    return 0;
}