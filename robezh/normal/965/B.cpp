#include <bits/stdc++.h>
using namespace std;

int n,k;
char c[105][105];
int cnt[105][105];

bool check_hori(int i, int j){
    for(int t = j; t < j+k; t++){
        if(c[i][t] == '#') return false;
    }
    return true;
}

void fill_hori(int i, int j){
    for(int t = j; t < j+k; t++) cnt[i][t]++;
}

bool check_ver(int i, int j){
    for(int t = i; t < i+k; t++){
        if(c[t][j] == '#') return false;
    }
    return true;
}

void fill_ver(int i, int j){
    for(int t = i; t < i+k; t++) cnt[t][j]++;
}

int main() {
    for(int i = 0; i < 105; i++) fill(cnt[i], cnt[i]+105, 0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-k+1; j++){
            if(check_hori(i,j)) fill_hori(i,j);
        }
    }
    if(k != 1){
        for(int i = 0; i < n-k+1; i++){
            for(int j = 0; j < n; j++){
                if(check_ver(i,j)) fill_ver(i,j);
            }
        }
    }
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cnt[i][j] > cnt[x][y]) x = i, y = j;
        }
    }
    cout << x+1 << " " << y+1 << endl;

    return 0;
}