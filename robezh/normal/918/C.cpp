#include <bits/stdc++.h>
using namespace std;

bool L[5005][5005], R[5005][5005];
string str;

int main() {
    getline(cin, str);
    for(int i = 0; i < 5005; i++){
        fill(L[i], L[i]+5005, false);
        fill(R[i], R[i]+5005, false);
    }
    int cur = 0;
    for(int i = 0; i < str.length(); i++){
        bool ok = true;
        cur = 0;
        for(int j = i; j < str.length(); j++){
            if(str[j] == ')') cur--;
            else cur ++;
            if(cur < 0) ok = false;
            L[i][j] = ok;
        }
    }
    for(int i = str.length()-1; i >= 0; i--){
        cur = 0;
        bool ok = true;
        for(int j = i; j >= 0; j--){
            if(str[j] == '(') cur --;
            else cur++;
            if(cur < 0) ok = false;
            R[j][i] = ok;
        }
    }
    int ans = 0;
    for(int i = 0; i < str.length(); i++){
        for(int j = i; j < str.length(); j++){
            if(L[i][j] && R[i][j] && (j - i + 1) % 2 == 0) ans ++;
        }
    }
    cout << ans;
}