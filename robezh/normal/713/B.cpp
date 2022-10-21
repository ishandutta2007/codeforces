#include <bits/stdc++.h>
using namespace std;

int n;

struct node {
    int x1, y1, x2, y2;
    string tostring() {
        return to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
    }
};

int ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int a; cin >> a;
    return a;
}

int get_hori() {
    int l = 0, r = n, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(ask(1, 1, n, mid) > 0) r = mid;
        else l = mid;
    }
    if(ask(1, 1, n, r) == 1 && ask(1, r+1, n, n) == 1) return r;
    return -1;
}

int get_ver() {
    int l = 0, r = n, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(ask(1, 1, mid, n) > 0) r = mid;
        else l = mid;
    }
    if(ask(1, 1, r, n) == 1 && ask(r + 1, 1, n, n)) return r;
    return -1;
}


node search(int xl, int xr, int yd, int yu) {
    for(int i = 19; i >= 0; i--) {
        int sh = (1 << i);
        if(xl + sh <= xr && ask(xl+sh, yd, xr, yu)) xl += sh;
        if(xr - sh >= xl && ask(xl, yd, xr-sh, yu)) xr -= sh;
        if(yd + sh <= yu && ask(xl, yd+sh, xr, yu)) yd += sh;
        if(yu - sh >= yd && ask(xl, yd, xr, yu-sh)) yu -= sh;
    }
    return {xl, yd, xr, yu};
}

int main() {
    cin >> n;
    node n1, n2;
    int h = get_hori();
    if(h != -1) {
        n1 = search(1, n, 1, h);
        n2 = search(1, n, h + 1, n);
    }
    else {
        int v = get_ver();
        n1 = search(1, v, 1, n);
        n2 = search(v+1, n, 1, n);
    }
    cout << "! " + n1.tostring() + " " + n2.tostring() << endl;
    fflush(stdout);
    return 0;
}