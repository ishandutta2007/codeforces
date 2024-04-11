#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int main(){
    cin >> n;
    getchar();
    getline(cin, str);

    int res = str.length();
    for(int i = 0; i < (str.length()); i++){
        if(i * 2 <= str.length()){
            if(str.substr(0,i) == str.substr(i,i)){
                res = min(res, n-i+1);
            }
        }
    }
    cout << res;
}