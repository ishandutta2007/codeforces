#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
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

#define N 2005

typedef bitset<N> bits;

bits e[N], d, y, x[N];
bool bs[N];
string p;
int a[N];

void binary(string p) {
    d = 0;
    int l = p.size(), i, j;
    reverse(all(p));
    while(p.size() <= (l << 3)) p += '0';
    for(i = 0; i < l; i ++) {
        a[i] = 0;
        for(j = 7; j >= 0; j --) a[i] = a[i] * 10 + p[8 * i + j] - '0';
    }
    ll s = 0;
    int tot = 0;
    while(l) {
        s = 0;
        for(i = l - 1; i >= 0; i --) {
            s = s * 1e8 + a[i];
            a[i] = s >> 32;
            s %= 1ll << 32;
        }
        for(i = 0; i < 32; i ++) d[tot ++] = (s >> i) & 1;
        while(l && a[l - 1] == 0) l --;
    }
}

int main() {
    int n, i, j, cnt;
    bool fl;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        cin >> p;
        binary(p);
        y = 0;
        fl = 0;
        for(j = 2000; j >= 0; j --) if(d[j]) {
            if(bs[j]) {
                d ^= e[j];
                y ^= x[j];
            }
            else {
                fl = 1;
                y[i].flip();
                bs[j] = 1;
                e[j] = d;
                x[j] = y;
                break;
            }
        }
        if(fl) {puts("0"); continue;}
        cnt = 0;
        for(j = 0; j < i; j ++) if(y[j]) cnt ++;
        printf("%d", cnt);
        for(j = 0; j < i; j ++) if(y[j]) printf(" %d", j);
        puts("");
    }
}