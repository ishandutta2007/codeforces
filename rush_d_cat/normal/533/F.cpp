#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 200000 + 10;
const int B = 131;

int n, m, nex[N][26], pw[N];
char s[N], t[N];
int idx[30], pos;
int H[30] = {0}, P[30] = {0};

bool cmp(int x, int y) {
    return nex[pos][x] < nex[pos][y];
}

bool chk(int x) {
    pos = x;
    for (int i = 0; i < 26; i ++) idx[i] = i;
    sort(idx, idx + 26, cmp);
    int hash[26] = {0};
    /*
    printf("chk %d: ", x);
    for (int i = 0; i < 26; i ++) {
        printf("%d ", H[idx[i]]);
    } printf("\n");
    */
    for (int i = 0; i < 26; i ++) {
        hash[i] = H[idx[i]];
        if (hash[i] != P[i]) return false;
    }
    
    int mp[26] = {0}; memset(mp, -1, sizeof(mp));
    for (int i = 0; i < 26; i ++) {
        int p = nex[x][i];
        if (p >= x + m) continue;
        //printf("mp[%d] = %d\n", s[p], t[nex[x][i] - x + 1]);
        mp[ s[p] - 'a' ] = t[ nex[x][i] - x + 1 ] - 'a';
    }

    for (int i = 0; i < 26; i ++) {
        if (mp[i] == -1) continue; 
        if (mp[ mp[i] ] != i && mp[ mp[i] ] != -1) return false;
    }
    return true;
}

int main() {
    pw[0] = 1; 
    for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * B;
    scanf("%d%d%s%s", &n, &m, s+1, t+1);

    for (int i = 0; i < 26; i ++) nex[m + 1][i] = m + 1;
    for (int i = m; i >= 1; i --) {
        for (int j = 0; j < 26; j ++) nex[i][j] = nex[i+1][j];
        nex[i][t[i]-'a'] = i;
    }
    
    int PP[30] = {0};
    for (int i = 1; i <= m; i ++) {
        PP[t[i]-'a'] = PP[t[i]-'a'] + pw[m - i];
    }

    pos = 1; 
    for (int i = 0; i < 26; i ++) idx[i] = i;
    sort(idx, idx + 26, cmp);
    for (int i = 0; i < 26; i ++) {
        P[i] = PP[idx[i]];
        //printf("%d ", P[i]);
    } //printf("\n");

    for (int i = 0; i < 26; i ++) nex[n + 1][i] = n + 1;
    for (int i = n; i >= 1; i --) {
        for (int j = 0; j < 26; j ++) nex[i][j] = nex[i+1][j];
        nex[i][s[i]-'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        H[s[i]-'a'] = H[s[i]-'a'] + pw[m - i];
    }
    vector<int> res;
    if (chk(1)) ans ++, res.push_back(1);
    for (int i = m + 1; i <= n; i ++) {
        H[ s[i-m] - 'a' ] -= pw[m - 1];
        for (int j = 0; j < 26; j ++) H[j] = H[j] * B;
        H[ s[i] - 'a' ] += pw[0];
        if (chk(i - m + 1)) ans ++, res.push_back(i - m + 1);
    }
    cout << ans << endl;
    for (auto x: res) {
        printf("%d ", x);
    }
}