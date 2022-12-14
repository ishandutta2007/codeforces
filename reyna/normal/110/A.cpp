#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    bool t = true;
    int counter = 0;
    cin >> a;
    for(int i = 0; i < a.length();i++){
        if(a[i] == '4' || a[i] == '7'){
            counter++;
        }
    }
    while(1){
        if(counter % 10 == 4 || counter % 10 == 7){
            if(counter >= 10){
                counter /= 10; 
            }else{
                break;
            }
        }else{
            t = false;
            break;
        }
    }
    if(t == true){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}