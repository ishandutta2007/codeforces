#include <bits/stdc++.h>;
using namespace std;

int n;
string str[1005];
int cnt[1005][30];

int ch(char a){return a - 'a';}
int same(int i, int j){
    for(int t = 0; t < 26; t++){
        if(cnt[i][t] != cnt[j][t]) return false;
    }
    return true;
}

bool uni(int i){
    for(int k = i+1; k < n; k++){
        if(same(i,k)) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str[i];
        for(char c : str[i]) cnt[i][ch(c)] = 1;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if (uni(i)) res++;
    }
    cout << res ;

}