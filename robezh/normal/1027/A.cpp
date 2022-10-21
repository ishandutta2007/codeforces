#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int dis(char a, char b){
    return b > a ? b - a : a - b;
}

bool check(string s){
    for(int i = 0; i < s.length(); i++){
        int dist = dis(s[i], s[s.length()-1-i]);
        if(dist != 0 && dist != 2) return false;
    }
    return true;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> s;
        printf(check(s) ? "YES\n" : "NO\n");
    }
}