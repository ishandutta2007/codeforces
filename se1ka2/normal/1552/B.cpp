#include <iostream>
using namespace std;

int a[50002][5];

bool win(int i, int j){
    int c = 0;
    for(int k = 0; k < 5; k++){
        if(a[i][k] < a[j][k]) c++;
    }
    if(c >= 3) return true;
    return false;
}

int rec(int l, int r){
    if(r - l == 1) return l;
    int i = rec(l, (r + l) / 2), j = rec((r + l) / 2, r);
    if(win(i, j)) return i;
    return j;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++) cin >> a[i][j];
        }
        int p = rec(0, n);
        bool f = true;
        for(int i = 0; i < n; i++){
            if(i != p && !win(p, i)) f = false;
        }
        if(f) cout << p + 1 << endl;
        else cout << -1 << endl;
    }
}