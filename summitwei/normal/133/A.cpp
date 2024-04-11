#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;
    bool hasReturn = false;
    for(int i=0; i<N.length(); i++){
        if(N[i] == 'H' || N[i] == 'Q' || N[i] == '9'){
            hasReturn = true;
        }
    }

    if(hasReturn){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}