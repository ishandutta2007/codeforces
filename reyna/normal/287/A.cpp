#include <iostream>
using namespace std;
int main(){
    string a[4];
    for(int i=0; i < 4; i++){
        cin >> a[i];
    }
    bool k = true;
    for(int i = 1; i < 4;i++){
        for(int j = 1;j < 4;j++){
            int counter = 0;
            if(a[i][j] == '#'){
                counter++;
            }
            if(a[i-1][j-1] == '#'){
                counter++;
            }
            if(a[i-1][j] == '#'){
                counter++;
            }
            if(a[i][j-1] == '#'){
                counter++;
            }
            if(counter != 2){
                cout << "YES";
                k = false;
                break;
            }
        }
        if(k == false){
            break;
        }
    }
    if(k == true){
        cout << "NO";
    }
}