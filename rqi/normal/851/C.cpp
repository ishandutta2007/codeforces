#include <bits/stdc++.h>

using namespace std;
int goodbad[12];
int coors[12][5];
int k = 0;
int sign(int x, int y){
    if(x == y){
       return 1;
    }
    else return 0;
}
int n;
int main() {
     ios_base::sync_with_stdio(false);
    cin >> n;
    if(n == 1){
        cout << 1 << '\n' << 1 << '\n';
    }
    else if(n == 2){
        cout << 2 << '\n' << 1  << '\n' << 2 << '\n';
    }
    else if(n > 11){
        cout << 0;
    }
    else{
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < 5; j++){
                cin >> coors[i][j];
            }
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                for(int l = 1; l < n+1; l++){
                    if(i!= j && i!=l && j!= l){
                    if((coors[j][0] - coors[i][0]) * (coors[l][0] - coors[i][0]) + (coors[j][1] - coors[i][1]) * (coors[l][1] - coors[i][1]) + (coors[j][2] - coors[i][2]) * (coors[l][2] - coors[i][2]) + (coors[j][3] - coors[i][3]) * (coors[l][3] - coors[i][3]) + (coors[j][4] - coors[i][4]) * (coors[l][4] - coors[i][4]) > 0){
                        goodbad[i] = 1;
                    }
                    
                    }
                }
            }
        }
        
        for(int i = 1; i < n+1; i++){
            if(goodbad[i] == 0){
                k = 1;
            }
        }
        cout << k << '\n';
        for(int i = 1; i < n+1; i++){
            if(goodbad[i] == 0){
                cout << i << '\n';
            }
        }
    }
    
}