#include <algorithm>
#include <iostream>
using namespace std;

int x[6][200005];

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t[6];
    int p[3] = {0, 1, 2};
    int c = 0;
    do{
        for(int i = 0; i < n; i++) t[c] += char('a' + p[i % 3]);
        for(int i = 1; i <= n; i++){
            x[c][i] = x[c][i - 1];
            if(t[c][i - 1] != s[i - 1]) x[c][i]++;
        }
        c++;
    }while(next_permutation(p, p + 3));
    while(m--){
        int l, r;
        cin >> l >> r;
        l--;
        int ans = n;
        for(int c = 0; c < 6; c++) ans = min(ans, x[c][r] - x[c][l]);
        cout << ans << endl;
    }
}