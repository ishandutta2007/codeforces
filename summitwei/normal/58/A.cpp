#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;

    int lettersCompleted = 0;

    for(int i=0; i<N.length(); i++){
        char hi = N[i];
        if(lettersCompleted == 0){
            if(hi == 'h'){
                lettersCompleted++;
            }
        } else if(lettersCompleted == 1){
            if(hi == 'e'){
                lettersCompleted++;
            }
        } else if(lettersCompleted == 2){
            if(hi == 'l'){
                lettersCompleted++;
            }
        } else if(lettersCompleted == 3){
            if(hi == 'l'){
                lettersCompleted++;
            }
        } else if(lettersCompleted == 4){
            if(hi == 'o'){
                lettersCompleted++;
            }
        }
    }

    if(lettersCompleted == 5){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}