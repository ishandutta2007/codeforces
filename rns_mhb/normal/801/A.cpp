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
    char s[111];
    scanf("%s", &s);
    int len = strlen(s), ans = 0, gas, i, j;
    for(j = 1; j < len; j ++) if(s[j] == 'K' && s[j - 1] == 'V') ans ++;
    for(i = 0; i < len; i ++) {
        s[i] = 'V' + 'K' - s[i];
        gas = 0;
        for(j = 1; j < len; j ++) if(s[j] == 'K' && s[j - 1] == 'V') gas ++;
        chkmax(ans, gas);
        s[i] = 'V' + 'K' - s[i];
    }
    printf("%d", ans);
}