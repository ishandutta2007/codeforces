#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000 + 10;
string read() {
    char s[52]; scanf("%s", s);
    string ans = "";
    for(int i=0;s[i];i++) ans += s[i];
    return ans;
}
int n, pos[N];
string s1[N],s2[N];

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        s1[i]=read(); s2[i]=read();
    }
    for(int i=1;i<=n;i++) {
        scanf("%d", &pos[i]);
    }
    bool ok = 1;
    string now = min(s1[pos[1]], s2[pos[1]]);
    for(int i=2;i<=n;i++) {
        if (min(s1[pos[i]], s2[pos[i]]) > now) {
            now = min(s1[pos[i]], s2[pos[i]]);
        } else if (max(s1[pos[i]], s2[pos[i]]) > now) {
            now = max(s1[pos[i]], s2[pos[i]]);
        } else {
            ok = 0;
        }
        //cout << now << endl;
    }
    printf("%s\n", ok ? "YES" : "NO");
}