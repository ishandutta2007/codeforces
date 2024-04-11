#include <iostream>
using namespace std;
int main(){
    int n,t,c;
    cin >> n >> t >> c;
    int counter = 0;
    int b = 0;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        if(a <= t){
            counter++;
        }else{
            counter = 0;
        }
        if(counter >= c){
            b++;
        }
    }
    cout << b;
}