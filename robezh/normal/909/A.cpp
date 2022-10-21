#include <bits/stdc++.h>
using namespace std;



int main() {
    string a,b;
    cin >> a >> b;
    string smllest = "zzzzzzzzzzzzzzzzzzz";
    //cout << a << " " << b;
    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            string now = a.substr(0,i) + b.substr(0,j);
            if(now.compare(smllest) < 0) smllest = now;
        }
    }
    cout << smllest;
}