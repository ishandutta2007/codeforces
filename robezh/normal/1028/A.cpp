#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[150];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    int mxi = -1, mni = 10000, mxj = -1, mnj = 10000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'B'){
                mxi = max(mxi, i);
                mni = min(mni, i);
                mxj = max(mxj, j);
                mnj = min(mnj, j);
            }
        }
    }
    cout << (mxi + mni) / 2 + 1 << " " << (mxj + mnj) / 2 + 1 << endl;
}