#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    int counter = 0;
    int max = 0;
    int numb = -1;
    for(int i = 0; i < a.length();i++){
        if(a[i] == '0'){
            numb = i;
            break;
        }
    }
    for(int i = 0; i < a.length();i++){
        if(numb == -1 && i!=0){
            cout << 1;
        }else if(numb != -1 && i != numb){
            cout << a[i];
        }
    }
}