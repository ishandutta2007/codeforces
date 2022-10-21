#include <bits/stdc++.h>
using namespace std;

int n;
int S[2][5], L[2][5], M[2];
string str;

int main(){
    cin >> n;
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            cin >> str;
            if(str[str.length()-1] == 'S') S[k][str.length()-1] ++;
            else if(str[str.length()-1] == 'M') M[k] ++;
            else L[k][str.length()-1] ++;
        }
    }
    for(int i = 0; i < 4; i++){
        int com = min(S[0][i], S[1][i]);
        S[0][i] -= com, S[1][i] -= com;
        com = min(L[0][i], L[1][i]);
        L[0][i] -= com, L[1][i] -= com;
    }
    int com = min(M[0], M[1]);
    M[0] -= com, M[1] -= com;
    int res = 0;
    for(int i = 0; i < 4; i++){
        res += (S[0][i] + L[0][i]);
    }
    res += M[0];
    cout << res;

}