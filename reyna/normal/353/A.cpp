#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter = 0;
    int counter2 = 0;
    bool k = false;
    for(int i = 0; i < n;i++){
        int a,b;
        cin >> a >> b;
        counter += a;
        counter2 += b;
        if(a % 2 == 1 && b % 2 == 0 || a % 2 == 0 && b % 2 == 1){
            k = true;
        }
    }
    if(counter % 2 == 0 && counter2 % 2 == 0){
        cout << 0;
        return 0;
    }
    if(counter % 2 == 1 && counter2 % 2 == 1 && k == true){
        cout << 1;
        return 0;
    }
    cout << -1;
    return 0;
}