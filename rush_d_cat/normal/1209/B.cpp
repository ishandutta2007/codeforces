#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n,a[N],b[N],vis[N];
char s[N];
int main() {
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        int now = s[i] == '1' ? 1 : 0;
        for(int j=0;j<=100000;j++) {
            if (j >= b[i] && j % a[i] == b[i] % a[i]) now = now ^ 1;
            if (now) vis[j] ++;
        }
    }
    int mx = 0;
    for(int i=0;i<N;i++) mx = max(mx, vis[i]);
    printf("%d\n", mx);
}
/*
7 * 5 * 9 * 8
*/