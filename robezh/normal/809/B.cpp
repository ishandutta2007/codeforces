#include <bits/stdc++.h>
using namespace std;

int n, k;

int ask(int x, int y) {
    cout << "1 " << x << " " << y << endl;
    fflush(stdout);
    string s;
    cin >> s;
    return s[0] == 'T';
}

int find(int l, int r) {
    int mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(ask(mid, mid + 1)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void answer(int x, int y) {
    cout << "2 " << x << " " << y << endl;
    fflush(stdout);
}

int main() {
    cin >> n >> k;
    int x = find(1, n);
    int l = (x > 1 ? find(1, x - 1) : -1);
    int r = (x < n ? find(x + 1, n) : -1);
    if(l != -1) if(!ask(l, x)) l = -1;
    if(l != -1) answer(x, l);
    else answer(x, r);

}