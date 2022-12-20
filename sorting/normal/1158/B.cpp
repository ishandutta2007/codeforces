#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    int x = (n - k) / 2 + 1;

    for(int i = 0; i < n; i++){
        if(i % x < x - 1){
            cout << "0";
        }
        else{
            cout << "1";
        }
    }

    cout << "\n";

    return 0;
}