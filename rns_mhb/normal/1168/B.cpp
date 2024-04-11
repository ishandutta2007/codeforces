#include<bits/stdc++.h>
using namespace std;

#define N 300010

char s[N];
vector <int> v[2], o[N];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i ++) v[s[i]-'0'].push_back(i);
    for(int i = 0; i < 2; i ++) {
        for(int j = 1; j < v[i].size(); j ++) {
            int x = v[i][j];
            for(int k = j - 1; k >= 0; k --) {
                int y = v[i][k];
                int z = 2 * x - y;
                if(z > n) break;
                if(s[z] == '0' + i) {
                    o[y].push_back(z);
                    break;
                }
            }
        }
    }
    set <int> s;
    long long ans = 0;
    for(int i = n; i; i --) {
        for(int j = 0; j < o[i].size(); j ++) s.insert(o[i][j]);
        if(s.empty()) continue;
        ans += n + 1 - (*s.begin());
    }
    printf("%I64d\n", ans);
}