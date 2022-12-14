#include <iostream>
using namespace std;
int main(){
    int w;
    cin >> w;
    if(w != 2 && w % 2 == 0){
        cout << "yes";
        return 0;
    }
    cout << "no";
    
}