#include <iostream>
#include <string>
using namespace std;
int a[4];
int counter;
int main(){
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    string b;
    cin >> b;
    for(int i = 0; i < b.length(); i++){
        if(b[i] == '4'){
            counter += a[3];
        }else if(b[i] == '3'){
            counter += a[2];
        }else if(b[i] == '2'){
            counter += a[1];
        }else if(b[i] == '1'){
            counter += a[0];
        }
    }
    cout << counter;
}