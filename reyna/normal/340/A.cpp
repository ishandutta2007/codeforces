#include <iostream>
using namespace std;
int main(){
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    int counter = 1;
    for(int i = 1; i <= 1000;i++){
        if(i > x && i>y){
            break;
        }else{
            if(x%i==0 && y%i == 0){
                counter = i;
            }
        }
    }
    if(a % (x*y/counter) != 0){
        a = a + x*y/counter;
    }
    cout << b/(x*y/counter) - a/(x*y/counter)+1;
}