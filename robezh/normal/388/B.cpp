#include <bits/stdc++.h>
using namespace std;

int k;
int cur = 2;

int mp[1005][1005];

void build(int pw, int cons){
    int las = 1;
    for(int i = 0; i < 10; i++){
        int nxt = ++cur;
        for(int j = 0; j < (i < pw ? 10 : 1); j++){
            int mid = ++cur;
            mp[mid][las] = mp[las][mid] = mp[mid][nxt] = mp[nxt][mid] = 1;
        }
        las = nxt;
    }
    for(int i = 0; i < cons; i++){
        int mid = ++cur;
        int nxt = 2;
        mp[mid][las] = mp[las][mid] = mp[mid][nxt] = mp[nxt][mid] = 1;
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < 10 && k > 0; i++){
        if(k % 10 != 0) build(i, k % 10);
        k /= 10;
    }
    cout << cur << endl;
    for(int i = 1; i <= cur; i++){
        for(int j = 1; j <= cur; j++){
            cout << (mp[i][j] ? "Y" : "N");
        }
        cout << endl;
    }
}