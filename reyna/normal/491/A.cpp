#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    for(int i = b;i <= a+b;i++){
        cout << i+1 << " ";
    }
    for(int i = b-1;i >= 0;i--){
        cout << i+1 << " ";
    }
    cout << endl;
    return 0;
}