#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << int((n+1)/2) * int((n+1)/2) + int((n/2))*int((n/2)) << endl;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if((i+j)% 2 == 0){
                cout << 'C';
            }else if((i+j)% 2 == 1){
                cout << '.';
            }
        }
        cout << endl;
    }
}