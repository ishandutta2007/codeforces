#include <iostream>
using namespace std;
int s[4];
int counter = 0;
int main(){
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 0 ; i < 3; i++){
        for(int j = i+1;j < 4; j++){
            if(s[i] == s[j]){
    //          cout << i << " " << j << endl;
                counter++;
            }
        }
    }
    //cout << counter;
    if(counter == 0){
        cout << 0;
    }else if(counter == 2){
        cout << 2;
    }else if(counter == 3){
        cout << 2;
    }else if(counter == 6){
        cout << 3;
    }else if(counter == 1){
        cout << 1;
    }
}