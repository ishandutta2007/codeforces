#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int N;
    cin >> N;
    vector<int> results(N);
    for(int i=0; i<N; i++){
        cin >> results[i];
    }

    int spec = 3;
    int canWork = true;
    for(int i=0; i<N; i++){
        if(results[i] == spec){
            canWork = false;
        } else{
            spec = 6 - spec - results[i];
        }
    }

    if(canWork){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}