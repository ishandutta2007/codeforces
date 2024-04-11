#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,n;
    int counter = 0;
    cin >> a >> b >> c >> d >> n;
    for(int i = 1; i < n+1;i++){
        if(i%a != 0 && i%b != 0 && i%c != 0 && i%d != 0){
            counter++;
        }
    }
    cout << n-counter;
}