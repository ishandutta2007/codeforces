#include <iostream>
#include <vector>
using namespace std;
const int N = 102;
int n;
char s[N];
vector<char> v, t;
bool ok(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int main() {
    scanf("%d %s", &n, s+1);
    for (int i = 1; i <= n; i ++) v.push_back(s[i]);
    for (int i = 0; i < 100; i ++) {
        t.clear(); t.push_back(v[0]);
        for (int j = 1; j < v.size(); j ++) {
            if (ok(v[j]) && ok(v[j-1])) continue;
            t.push_back(v[j]);
        }
        v = t;
    }
    for (int i = 0; i < v.size(); i ++)
        printf("%c", v[i]);
}