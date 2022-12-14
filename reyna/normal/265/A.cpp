#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    int ptr = 0;
    for(int i = 0; i < b.length();i++){
        if(b[i] == a[ptr]){
            ptr++;
        }
    }
    cout << ptr+1;
}