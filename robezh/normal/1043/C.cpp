#include <bits/stdc++.h>
using namespace std;

string str;
int res[1005];

bool mono(string str){
    int n = str.length();
    int l = 0, r = n - 1;
    while(l + 1 < n && str[l+1] == str[l]) l ++;
    while(r >= 1 && str[r - 1] == str[r]) r--;

    return (l + 1 >= r);
}

int main(){
    int n;
    cin >> str;
    n = str.length();
    str.push_back('b');
    for(int i = 1; i <= n; i++){
        if(!mono(str.substr(0, i + 1))){
            res[i] = 1;
            reverse(str.begin(), str.begin() + i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
}