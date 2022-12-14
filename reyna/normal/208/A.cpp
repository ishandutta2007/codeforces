#include <iostream>
#include <string>
using namespace std;
bool arr[200];
int main(){
    string a;
    cin >> a;
    bool t = true;
    bool k = true;
    if(a.length() < 3){
        cout << a;
        return 0;
    }
    for(int i = 0; i < a.length()-2;i++){
        if(a[i] == 'W' && a[i+1] == 'U' && a[i+2] == 'B'){
            arr[i] = true;
            arr[i+1] = true;
            arr[i+2] = true;
        }
    }
    for(int i = 0; i < a.length();i++){
        if(arr[i] == false){
            cout << a[i];
            t = false;
            k = false;
        }
        if(arr[i] == true && t == false && k == false){
            cout << " ";
            t = true;
        }
    }
}