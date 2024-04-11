#include <iostream>
using namespace std;
int main(){
    int a,b;
    int remainder = 0;
    cin >> a >> b;
    int counter = a;
    while(1){
        a+= remainder;
        if(a/b == 0){
            break;
        }
        remainder = a%b;
        a /= b;
        counter += a;
    }
    cout << counter;
}