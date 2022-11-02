#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;

    bool onCaps = true;

    for(int i=1; i<N.length(); i++){
        if(N[i]==tolower(N[i])){
            onCaps = false;
        }
    }

    if(onCaps){
        if(N[0] == tolower(N[0])){
            N[0] = toupper(N[0]);
        } else{
            N[0] = tolower(N[0]);
        }
        for(int i=1; i<N.length(); i++){
            N[i] = tolower(N[i]);
        }
    }

    cout << N;
    return 0;
}