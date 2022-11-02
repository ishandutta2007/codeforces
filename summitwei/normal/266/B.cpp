#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    string places;
    cin >> places;
    for(int i=0; i<T; i++){
        int j=0;
        while(j < (N-1)){
            if(places[j]=='B' && places[j+1]=='G'){
                places[j]='G';
                places[j+1]='B';
                j++;
            }
            j++;
        }
    }

    cout << places;
    return 0;
}