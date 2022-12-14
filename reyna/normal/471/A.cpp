#include <iostream>
using namespace std;
int L[10];
int main(){
    int k = false;
    int b = -1;
    for(int i = 0; i < 6;i++){
        int a;
        cin >> a;
        L[a]++;
        if(L[a] >= 4){
            int b = a;
            k = true;
        }
    }
    if(!k){
        cout << "Alien" << endl;
        return 0;
    }
    for(int i = 0; i < 10;i++){
        if(L[i] == 6){
            cout << "Elephant" << endl;
            return 0;
        }
        if(i != b && L[i] == 2){
            cout << "Elephant" << endl;
            return 0;
        }
    }
    cout << "Bear" << endl;
    return 0;
}