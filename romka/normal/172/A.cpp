#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
string s[30010];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = s[0].size();
    for (int i = 1; i < n; i++)
        for (int j = 0; j < ans; j++)
            if (j == (int)s[i].size() || s[i][j] != s[0][j]) {
                ans = j;
                break;
            }
        
    printf("%d\n", ans);
    return 0;
}