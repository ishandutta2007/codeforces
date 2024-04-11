#include<bits/stdc++.h>
using namespace std;

int n,a,b;
int t[55][55];

bool f(){
    for(int i = 1; i <= n; i++){
        if(a != i && b != i){
            if(t[a][i] * t[i][b] > 0) return t[a][i] > 0;
        }
    }
    return true;
}

int main(){
    for(int i = 0; i < 55; i++) fill(t[i], t[i]+55, 0);

    cin >> n;
    for(int i = 0; i < n * (n-1) / 2 - 1; i++){
        cin >> a >> b;
        t[a][b] = 1, t[b][a] = -1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(!t[i][j]){
                a = i, b = j;
                break;
            }
        }
    }
    if(f()) cout << a << " " << b;
    else cout << b << " " << a;

}