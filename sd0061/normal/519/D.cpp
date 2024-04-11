#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int val[26];
LL s[N];
int n;
char str[N];
map<LL , int> h[26];

void work() {
    int i , j;
    for (i = 0 ; i < 26 ; ++ i) {
        scanf("%d" , &val[i]);
    }
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    LL res = 0;
    for (i = 1 ; i <= n ; ++ i) {
        s[i] = s[i - 1] + val[str[i] - 'a'];
        res += h[str[i] - 'a'][s[i - 1]];
        ++ h[str[i] - 'a'][s[i]];
    }
cout << res << endl;
}

int main() {
    work();
    return 0;
}