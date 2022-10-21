#include <bits/stdc++.h>
using namespace std;

struct piece{
    int n;
    string str[105];
};

int n;
int per[4];
string p[4][105];
string str[205];

void conte(){
    for(int i = 0; i < n; i++){
        str[i] = p[per[0]][i] + p[per[1]][i];
    }
    for(int i = 0; i < n; i++){
        str[i+n] = p[per[2]][i] + p[per[3]][i];
    }
}

int calc_min(int k){
    int res = 0;
    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < 2*n; j++){
            res += ((str[i][j]-'0') == (i + j + k) % 2);
        }
    }
    return res;
}

int calc(){
    return min(calc_min(1), calc_min(0));
}

int main() {
    cin >> n;
    for(int i = 0; i < 4; i++) per[i] = i;
    for(int i = 0; i < 4; i++){
        getchar();
        for(int j = 0; j < n; j++){
            getline(cin, p[i][j]);
        }
    }
    int res = 10000000;
    do{
        conte();
        res = min(res, calc());
    }while(next_permutation(per, per+4));
    cout << res;
}