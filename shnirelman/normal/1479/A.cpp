#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;

int n;
int a[N];

int get(int i) {
    if(i == -1 || i == n)
        return INF;
    if(a[i] != -1)
        return a[i];
    cout << "? " << i + 1 << endl;

    int x;
    cin >> x;

    return a[i] = x - 1;
}


int finish(int ind) {
    cout << "! " << ind + 1 << endl;
    exit(0);
}

void check(int i) {
    if(get(i) < get(i - 1) && get(i) < get(i + 1))
        finish(i);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        a[i] = -1;

    int l = 0, r = n;
    while(r - l > 3) {
        int m = (l + r) / 2;

        check(l);
        check(r - 1);
        check(m);

        if(get(m) > get(m - 1))
            r = m;
        else
            l = m;

//        if(get(l) < get(r)) {
//            if(get(m) - get(l) == m - l)
//                l = m + 1;
//            else
//                r = m;
//        } else {
//            if(get(m) - get(r - 1) == r - m)
//                r = m;
//            else
//                l = m + 1;
//        }
    }

    for(int i = l; i < r; i++)
        check(i);
}