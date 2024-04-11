//In the name of God
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << (n * n)/4 << endl;
    int f = n/2;
    int s = n;
    for(int i = 0; i < f;i++){
        for(int j = f; j < n;j++){
            cout << i+1 << ' ' << j+1 << endl;
        }
    }
    return 0;
}