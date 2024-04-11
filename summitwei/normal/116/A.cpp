#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int maxCap = 0;
    int current = 0;
    for(int i=0; i<N; i++){
        int A, B;
        cin >> A >> B;

        current = current - A + B;

        if(current > maxCap){
            maxCap = current;
        }
    }

    cout << maxCap;

    return 0;
}