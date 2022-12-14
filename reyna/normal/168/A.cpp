#include <iostream>
using namespace std;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    double a = (double)(n*y)/100;
    int b = a;
    if(b < a){
        if(b+1-x > 0){
            cout << b+1-x;
        }else{
            cout << 0;
        }
    }else{
        if(b-x > 0){
            cout << b-x;
        }else{
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}