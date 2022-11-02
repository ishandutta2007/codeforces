#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string colors;
    cin >> colors;

    int count = 0;
    for(int i=1; i<N; i++){
        if(colors[i] == colors[i-1]){
            count++;
        }
    }
    cout << count;
    return 0;
}