#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,len;
int cnt[3][250];
int mx[3];
string win[3] = {"Kuro", "Shiro", "Katie"};
string str[3];

int main() {
    cin >> n;
    getchar();
    for(int i = 0; i < 3; i++) getline(cin, str[i]);
    for(int i = 0; i < 3; i++){for(char c : str[i]) cnt[i][c]++;}
    len = str[0].length();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 250; j++){
            int cur = 0;
            if(cnt[i][j] == len && n == 1) cur = len - 1;
            else cur = min(cnt[i][j]+n, len);
            mx[i] = max(cur, mx[i]);
        }
    }
    if(mx[0] > mx[1] && mx[0] > mx[2]) cout << win[0];
    else if(mx[1] > mx[0] && mx[1] > mx[2]) cout << win[1];
    else if(mx[2] > mx[1] && mx[2] > mx[0]) cout << win[2];
    else cout << "Draw";
}