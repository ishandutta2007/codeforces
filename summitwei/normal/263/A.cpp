#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 0;
    int good;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> num;
            if(num == 1){
                good = abs(i-2) + abs(j-2);
            }
        }
    }
    cout << good;
    return 0;
}