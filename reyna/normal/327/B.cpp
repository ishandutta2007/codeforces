#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 999999-n+1;i<1000000;i++){
        cout << i << " ";
    }
    return 0;
}