#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

struct ts{
    int d, l, r;
};

bool operator < (ts a, ts b){
        return (a.d < b.d) || (a.d == b.d && a.l < b.l) || (a.d == b.d && a.l == b.l && a.r < b.r);
}

char a[500001];
int b[500001], next[500001], prev[500001], f[500001], t[500001];
bool del[500001];
set <ts> s;

ts make_ts(int d, int l, int r){
    ts s;
    s.d = d;
    s.l = l;
    s.r = r;
    return s;
};

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%c", &a[i]);
    }
    scanf("\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; i++){
        next[i] = -1;
        prev[i] = -1;
    }
    for(int i = 0; i < n - 1; i++){
        next[i] = i + 1;
    }
    for(int i = 1; i < n; i++){
        prev[i] = i - 1;
    }
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            s.insert(make_ts(abs(b[i] - b[i - 1]), i - 1, i));
        }
    }
    int k = 0;
    while(s.size() > 0){
        ts res;
        res = *(s.begin());
        s.erase(*(s.begin()));
        if(del[res.l] || del[res.r]){
            continue;
        }
        del[res.l] = true;
        del[res.r] = true;
        int p1 = prev[res.l];
        int p2 = next[res.r];
        if(p1 > -1){
            next[p1] = p2;
        }
        if(p2 > -1){
            prev[p2] = p1;
        }
        if(p1 > -1 && p2 > -1 && a[p1] != a[p2]){
            s.insert(make_ts(abs(b[p2] - b[p1]), p1, p2));
        }
        f[k] = res.l;
        t[k] = res.r;
        k++;
    }
    printf("%d\n", k);
    for(int i = 0; i < k; i++){
        printf("%d %d\n", f[i] + 1, t[i] + 1);
    }
    return 0;
}