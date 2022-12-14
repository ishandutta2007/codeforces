#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    int counter = 0;
    for(int i = 0; i < a.length(); i++){
        if(int(a[i]) < 97){
            counter++;
        }
    }
    if(counter > a.length()/2){
        for(int i = 0; i < a.length();i++){
            if(int(a[i]) > 96){
                a[i] = char(int(a[i])-32);
            }
        }
    }else{
        for(int i = 0; i < a.length();i++){
            if(int(a[i]) < 97){
                a[i] = char(int(a[i])+32);
            }
        }
    }
    for(int i = 0; i < a.length();i++){
        cout << a[i];
    }
}