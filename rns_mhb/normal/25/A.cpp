#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back

#define inf 1e9
#define INF 1e18

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

int main() {
    int n, i, o = 0, e = 0, a[111];
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        if(a[i] & 1) o ++;
        else e ++;
    }
    if(o == 1) {
        for(i = 1; i <= n; i ++) if(a[i] & 1) {
            printf("%d\n", i);
            return 0;
        }
    } else {
        for(i = 1; i <= n; i ++) if(a[i] % 2 == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
}