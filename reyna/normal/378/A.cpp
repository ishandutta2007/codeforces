#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,awins=0,bwins=0,draw=0;
    cin >> a >> b;
    for(int i = 1; i < 7; i++){
        if(abs(a-i) < abs(i-b)){
            awins++;
        }else if(abs(a-i) > abs(b-i)){
            bwins++;
        }else{
            draw++;
        }
    }
    cout << awins << " " << draw << " " << bwins;
}