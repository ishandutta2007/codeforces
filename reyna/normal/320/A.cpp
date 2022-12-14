#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.length(); i++){
        if(i == 0 && a[i] == '1'){
            
        }else if(i == 0 && a[i] != '1'){
            cout << "NO";
            return 0;
        }
        if(i < a.length()-2){
            if(a[i] == '4' && a[i+1] == '4' && a[i+2] == '4'){
                cout << "NO";
                return 0;
            }
        }
        if(a[i] != '4' && a[i] != '1'){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}