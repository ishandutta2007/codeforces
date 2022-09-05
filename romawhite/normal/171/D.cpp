#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n == 3){
     cout << 1 << endl;
     return 0;   
    }
    if (n == 1){
        cout << 2 << endl;
        return 0;
    }
    if (n == 4){
        cout << 2 << endl;
        return 0;
    }
    if (n == 5){
        cout << 1 << endl;
        return 0;
    }
    if (n == 2){
    cout << 3 << endl;
    return 0;
    }
    throw -1;
}