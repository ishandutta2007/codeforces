#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int get_m(int t, int k){
    int l = 1, r = t, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(t/mid == k) return mid;
        else if(t/mid > k) l = mid+1;
        else r = mid-1;
    }
    if(l == r && t/l == k) return l;
    return -1;
}

P check(int x){
    int s = max(1, (int)(sqrt(x)));
    for(int i = 0; i < 60000; i++){
        if(i * i - x < 0) continue;
        int t = (int)(sqrt(i * i - x) + 0.0005);
        if(t * t + x == i * i){
            int m = get_m(i,t);
            if(m != -1) return make_pair(i,m);
        }
    }
    return make_pair(-1,-1);
}

int main() {
    int t,a;
    cin >> t;
    while(t--){
        cin >> a;
        P res = check(a);
        if(res.first == -1) cout << "-1" << endl;
        else cout << res.first << " " << res.second << endl;
    }
}