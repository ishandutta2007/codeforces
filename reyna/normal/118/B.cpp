#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter = 0;
    for(int i = 0; i < 2*n+2;i++){
        counter = 0;
        bool t = false;
        for(int j = 0; j<2*n+2;j++){
            if((n-(abs(n-i) + abs(n-j)))<0 && j<n){
                cout << "  ";
            }else if((n-(abs(n-i) + abs(n-j)))>=0){
                if(t == true){
                    cout << " " << (n-(abs(n-i) + abs(n-j)));
                }else{
                    cout << (n-(abs(n-i) + abs(n-j)));
                    t = true;
                }
            }
        }
        cout << endl;
    }
}