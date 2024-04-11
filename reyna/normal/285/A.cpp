#include <iostream>
using namespace std;
int main(){
    int n;
    int k;
    cin >> n >> k;
    for(int i = k+1; i > 0;i--){
        cout << i << " ";
    }
    for(int i = k+2;i<=n;i++){
        cout << i << " ";
    }
}