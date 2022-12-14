#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    int counter = 0;
    for(int i = 0; i <= b; i++){
        if(n-1-i>=a){
            counter++;
        }
    }
    cout << counter;
}