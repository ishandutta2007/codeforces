#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
char s[110];
bool f[110][2][2];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        bool ok = false;
        for (int i=0;i<=n;i++) {
            vector<int>q;
            for (int j=0;j<=i;j++) if (s[j]=='1') q.push_back(j);
            for (int j=i+1;j<=n;j++) if (s[j] == '0') q.push_back(j);
            bool tok = true;
            for (int j=0;j<int(q.size())-1;j++) {
                if (q[j] + 1 == q[j + 1]) tok = false;
            }
            ok |= tok;
        }
        puts(ok ? "YES" : "NO");
    }
}