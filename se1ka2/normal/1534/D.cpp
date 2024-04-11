#include <iostream>
using namespace std;

int d[2002][2002];
bool b[2002][2002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int r = 0; r < n; r++){
        for(int i = 0; i < n; i++) d[r][i] = -1;
    }
    cout << "? " << 0 + 1 << endl;
    for(int i = 0; i < n; i++) cin >> d[0][i];
    int c = 0;
    for(int i = 0; i < n; i++) c += d[0][i] % 2;
    int k = 0;
    if(c * 2 < n) k = 1;
    for(int r = 1; r < n; r++){
        if(d[0][r] % 2 == k){
            cout << "? " << r + 1 << endl;
            for(int i = 0; i < n; i++) cin >> d[r][i];
        }
    }
    cout << "!" << endl;
    for(int l = 0; l < n; l++){
        for(int r = 0; r < n; r++){
            if(d[0][r] == l && d[r][0] != -1){
                for(int i = 0; i < n; i++){
                    if(d[r][i] == 1 && !b[r][i] && !b[i][r]){
                        cout << i + 1 << " " << r + 1 << endl;
                        b[r][i] = b[i][r] = true;
                    }
                }
            }
        }
    }
}