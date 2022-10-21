#include <bits/stdc++.h>
using namespace std;

int n, m, tmp;
bool exi[105][105];


bool is_subset(int a, int b){
    for(int i = 1; i <= 100; i++){
        if(exi[a][i] > exi[b][i]) return false;
    }
    return true;
}

bool good(int x){
    for(int i = 0; i < n; i++){
        if(i != x && is_subset(i,x)) return false;
    }
    return true;
}

int main(){
    for(int i = 0; i < 105; i++) fill(exi[i], exi[i]+105, false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> tmp;
            exi[i][tmp] = true;
        }
    }
    for(int i = 0; i < n; i++){
        if(good(i)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}