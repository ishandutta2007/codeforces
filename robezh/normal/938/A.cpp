#include <bits/stdc++.h>
using namespace std;

int n;
string str;

bool isV(int k){
    char c = str[k];
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

bool should(int k){
    return isV(k) && isV(k-1);
}

int main() {
    cin >> n;
    getchar();
    getline(cin, str);
    for(int i = 0; i < 100; i++){
        for(int j = 1; j < str.length(); j++){
            if(should(j)){
                str.erase(str.begin()+j);
                break;
            }
        }
    }
    cout << str;
}