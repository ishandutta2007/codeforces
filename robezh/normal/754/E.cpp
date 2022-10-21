#include <bits/stdc++.h>
using namespace std;

const int N = 405;
typedef bitset<N> bs;

int n,m,r,c;
string s[N], t[N];
bs b[26][N];
bs good[N];

bs shift(bs bsa, int k){
    return (bsa >> (k % m)) | (bsa << (((m-k) % m + m) % m));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++) b[s[i][j]-'a'][i][j]= 1;
    }
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> t[i];

    for(int i = 0; i < n; i++) good[i].set();
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(t[i][j] == '?') continue;
            for(int k = 0; k < n; k++){
                good[k] &= shift(b[t[i][j]-'a'][(k+i)%n], j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << good[i][j];
        cout << endl;
    }
}