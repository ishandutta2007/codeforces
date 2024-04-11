#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool kek = true;
    while(kek){
        if(n % 10 == 0){
            n = n/10;
        } else{
            kek = false;
        }
    }

    string ispal;
    ispal = to_string(n);



    string good = ispal;
    string bad = good;
    reverse(bad.begin(), bad.end());

    if(good == bad){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}