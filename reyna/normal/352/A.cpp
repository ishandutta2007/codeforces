#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool t = false;
    int tedad = 0;
    int tedad1 = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >>a;
        if(a == 0){
            t = true;
            tedad1++;
        }
        if(a == 5){
            tedad++;
        }
    }
    if(t == false){
        cout << -1;
        return 0;
    }
    for(int i = 1; 9*i <= tedad;i++){
        cout << 555555555;
        t = false;
    }
    for(int i = 0; i < tedad1;i++){
        cout << 0;
        if(t != false){
            break;
        }
    }
    return 0;
}