#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    bool k = false;
    for(int i = 0; i <= a;i++){
        if(i > b){
            break;
        }
        if(c-b+i == a-i){
            cout << i << " " << b-i << " " << a-i << endl;
            k = true;
            break;
        }
    }
    if(k == true){
        return 0;
    }
    cout << "Impossible";
    return 0;
}