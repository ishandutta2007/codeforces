#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    if(a[0] != '-'){
        cout << a;
        return 0;
    }
    if(a.length() == 3  && a[2] == '0'|| a.length() == 2){
        cout << 0;
        return 0;
    }
    if(int(a[a.length()-1]) > int(a[a.length()-2])){
        for(int i = 0; i<a.length(); i++){
            if(i != (a.length()-1)){
                cout << a[i];
            }
        }
    }else{
        for(int i = 0; i<a.length(); i++){
            if(i != (a.length()-2)){
                cout << a[i];
            }
        }
    }
}