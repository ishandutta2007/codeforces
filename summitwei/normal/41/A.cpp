#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    if(a.length() != b.length()){
        cout << "NO";
        return 0;
    }

    for(int i=0; i<a.length(); i++){
        if(a[i] != b[b.length()-1-i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}