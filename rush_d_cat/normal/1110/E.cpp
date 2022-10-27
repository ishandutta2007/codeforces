#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;

const int N = 100000 + 10;
int n,c[N],t[N],vis[N];
multiset<int> st1,st2;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
        if(i>=2) st1.insert(c[i]-c[i-1]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&t[i]);
        if(i>=2) st2.insert(t[i]-t[i-1]);
    }
    if(c[1]!=t[1] || c[n]!=t[n]) {
        return !printf("No\n");
    }
    printf("%s\n", st1==st2?"Yes":"No");
}