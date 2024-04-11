#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n , cnt[256] , size;
char s[N];

int main() {
    scanf("%d%s" , &n , s);

    set<int> dict;
    for (int i = 0 ; i < n ; ++ i) {
        dict.insert(s[i]);
    }
    int res = n;
    for (int i = 0 , j = 0 ; i < n ; ++ i) {
        while (j < n && size < dict.size()) {
            ++ cnt[s[j]];
            if (cnt[s[j]] == 1) {
                ++ size;
            }
            j ++;
        }
        if (size == dict.size()) {
            res = min(res , j - i);
        }
        -- cnt[s[i]];
        if (cnt[s[i]] == 0) {
            -- size;
        }
    }
    cout << res << endl;
}