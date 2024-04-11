#include <bits/stdc++.h>
 
#define f first
#define s second
 
using namespace std;
using li = long long;
 
vector<vector<int>> a(3);
vector<vector<li>> s(3);
 
li get2(int m) {
    return s[0][min(int(a[0].size()), m)];
}
 
li get1(int m) {
    int l = -1, r = min(int(a[1].size()), m / 2) + 1;
    while(r - l > 2) {
        int m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
 
        if(get2(m - m1 * 2) + s[1][m1] < get2(m - m2 * 2) + s[1][m2])
            l = m1;
        else
            r = m2;
    }
 
    return get2(m - (l + 1) * 2) + s[1][l + 1];
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
 
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
 
        a[x - 1].push_back(y);
    }
 
    //cout << "sf" << endl;
 
    for(int i = 0; i < 3; i++)
        sort(a[i].rbegin(), a[i].rend());
//cout << "sf" << endl;
    for(int i = 0; i < 3; i++) {
        //cout << a[i].size() << endl << endl;
        s[i].resize(a[i].size() + 1, 0);
        //cout << s[i].size() << endl << endl;
//cout << i << endl;
        for(int j = 1; j < s[i].size(); j++) {
//cout << "j " << j << endl;
            s[i][j] = s[i][j - 1] + a[i][j - 1];
            //cout << j << endl;
        }
 
    }
//cout << "sf" << endl;
    li ans = 0;
    for(int i = 0; i <= a[2].size() && i * 3 <= m; i++) {
        //cout << "3 " << i << endl;
        ans = max(ans, get1(m - i * 3) + s[2][i]);
    }
 
    cout << ans;
}