#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pnt{
    int x, y;
    ll dist() {return 1ll * x * x + 1ll * y * y;}
    pnt operator - (const pnt &a) const {return pnt{x - a.x, y - a.y};}
    ll operator * (const pnt &a) const {return 1ll * x * a.y - 1ll * y * a.x;}
    void in() {scanf("%d%d", &x, &y);}
    void rot() {swap(x, y); x *= -1;}
    bool net(pnt a) {
        if(x == 0 && y == 0) return a.x == 0 && a.y == 0;
        return a.dist() % dist() == 0 && a * (*this) % dist() == 0;
    }
} A, B, C;

int main() {
    A.in(), B.in(), C.in();
    if(C.net(B - A)) {puts("YES"); return 0;}
    A.rot();
    if(C.net(B - A)) {puts("YES"); return 0;}
    A.rot();
    if(C.net(B - A)) {puts("YES"); return 0;}
    A.rot();
    if(C.net(B - A)) {puts("YES"); return 0;}
    puts("NO");
}