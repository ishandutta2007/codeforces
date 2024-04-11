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
#define N 100005

const int PI = 60 * 60 * 12;

int main() {
    int h[3], st, ed;
    scanf("%d%d%d%d%d", &h[0], &h[1], &h[2], &st, &ed);
    h[0] = PI / 12 * h[0] + PI / 720 * h[1] + h[2];
    h[0] %= PI;
    h[1] = PI / 60 * h[1] + PI / 3600 * h[2];
    h[2] = PI / 60 * h[2];
    st *= 60 * 60; ed *= 60 * 60;
    st %= PI; ed %= PI;
    sort(h, h + 3);
    if(h[0] <= st && h[0] <= ed && st <= h[1] && ed <= h[1]) {puts("YES"); return 0;}
    if(h[1] <= st && h[1] <= ed && st <= h[2] && ed <= h[2]) {puts("YES"); return 0;}
    if(st <= h[0]) st += PI;
    if(ed <= h[0]) ed += PI;
    h[0] += PI;
    if(h[2] <= st && h[2] <= ed && st <= h[0] && ed <= h[0]) {puts("YES"); return 0;}
    puts("NO");
}