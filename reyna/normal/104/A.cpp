#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n <= 10){
        cout << 0 << endl;
        return 0;
    }
    if(n == 20){
        cout << 15 << endl;
        return 0;
    }
    if(n > 21){
        cout << 0 << endl;
        return 0;
    }
    cout << 4 << endl;
    return 0;
}