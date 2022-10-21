#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef long long ll;

int n, L;
int a[N], b[N];
int bx[3 * N];
int ins[3 * N], outs[3 * N];

void add(int l, int r, int i){
    for(int j = -1; j <= 1; j++){
        int li = l - i + j * n, ri = r - i + j * n;
        if(li >= 0 && ri < 3 * n) ins[li]++, outs[ri]++;
    }
}

bool check(int range){
    fill(ins, ins + 3 * N, 0);
    fill(outs, outs + 3 * N, 0);

    int l = 0, r = 0;

    for(int i = 0; i < n; i++){
        while(l < 3 * n && bx[l] < a[i] - range) l++;
        while(r < 3 * n && bx[r] <= a[i] + range) r++;
        if(l >= r) return false;
//        ins[l - i] ++, outs[r - i] ++;
        if(r - l >= n) ins[0] ++;
        else add(l, r, i);
    }
    int cur = 0;
    for(int i = 0; i < 3 * N; i++){
        cur += (ins[i] - outs[i]);
        if(cur == n) return true;
    }
    return false;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> L;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for(int i = 0; i < 3 * n; i++) bx[i] = b[i % n] + (i / n - 1) * L;

    int l = -1, r = L, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;

}