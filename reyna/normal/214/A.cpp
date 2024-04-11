#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int counter = 0;
    for(int i = 0; i*i <= n; i++){
        int j = n-(i*i);
        if((i + j*j) == m){
            counter++;
        }
    }
    cout << counter;
}