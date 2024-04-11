#include<bits/stdc++.h>
using namespace std;
#define N 5009
int l, r;
int n, cnt;
int sto[N];
struct dat{
    int x, y, id;
    dat(int x = 0, int y = 0, int id = 0) :x(x), y(y), id(id){}
}p[N];
bool cmp(dat a, dat b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}
bool ok(int id) {
    for(int j = 1; j < n; j ++) if(j != id) {
        if(j - 1 == id) {
            if(j == 1) continue;
            if(p[j].x < p[j-2].y) return 0;
            continue;
        }
        if(p[j].x < p[j-1].y) return 0;
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d%d", &l, &r), p[i] = dat(l, r, i + 1);
    sort(p, p + n, cmp);
    for(int i = 0; i < n; i ++) if(ok(i)) sto[cnt ++] = p[i].id;
    printf("%d\n", cnt);
    sort(sto, sto + cnt);
    for(int i = 0; i < cnt; i ++) printf("%d ", sto[i]);
    puts("");
    return 0;
}