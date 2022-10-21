#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e6 + (int)2e5;

int num[N];
int n;

struct node {
    int mx1, mx2;
    void add(int x) {
        if(x > mx1) swap(mx1, x);
        if(x > mx2) swap(mx2, x);
    }
    void merge(node &o) {
        add(o.mx1);
        add(o.mx2);
    }
} nd[N];

struct FWT {
    // Please set N!!!
    int N;
    void FWTand(node *a) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    a[j + k].merge(a[j + k + mid]);
    }
} fwt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        nd[num[i]].add(i);
    }
    fwt.N = (1 << 21);
    fwt.FWTand(nd);
    int fres = 0;
    for(int i = 1; i <= n - 2; i++) {
        int mask = 0;
        int res = num[i];
        for(int j = 20; j >= 0; j--) {
            if(!((res >> j) & 1) && nd[mask | (1 << j)].mx2 > i) {
                mask |= (1 << j);
                res |= (1 << j);
            }
        }
        fres = max(fres, res);
    }
    cout << fres << "\n";


}