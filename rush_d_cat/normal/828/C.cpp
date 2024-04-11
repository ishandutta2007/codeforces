#include <iostream>
#include <cstring>
using namespace std;
const int NICO = 2000000+10;
int n, k[100000+10], x; 
string t[100000+10];

int len[NICO], id[NICO];
char ans[NICO];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    int last_pos = 0;
    for(int i = 1; i <= n; ++ i) {
        cin >> t[i] >> k[i];
        int lent = t[i].length(); 
        for(int j = 1; j <= k[i]; ++ j) {
            cin >> x;
            last_pos = max(last_pos, x + lent - 1);
            if(lent > len[x]) {
                len[x] = lent;
                id[x] = i; 
            }
        }
    }

    int last = 0;
    for(int i = 1; i <= last_pos; ++ i) {
        if(len[i] == 0 && i > last) {
            ans[i] = 'a';
        } else {
            for(int j = max(i, last+1); j <= i + len[i] - 1; ++ j) {
                ans[j] = t[ id[i] ][j - i];
            }
            last = max(i + len[i] - 1, last);
        }        
    }
    for(int i=1;i<=last_pos;i++) {
        cout << ans[i];
    }
    cout << endl;
}