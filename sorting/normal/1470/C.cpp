#include <bits/stdc++.h>

using namespace std;

int n, k;

int query(int q){
    cout << "? " << q << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int fix(int a){
    a %= n;
    if(a < 0) a += n;
    if(a == 0) a = n;
    return a;
}

void give_answer(int ans){
    cout << "! " << ans << "\n";
    cout.flush();
    exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    query(1);
    int curr = 1;
    for(int i = 1; true; ++i, curr += i){
        int q = fix(curr - i);
        int t = query(q);
        if(t < k){
            int l = fix(q + 1), r = fix(q + i);
            while(l != r){
                int mid;
                if(l < r) mid = (l + r) >> 1;
                else mid = fix((l + r + n) >> 1);
                if(query(mid) == k){
                    give_answer(mid);
                    return 0;
                }
                if(query(mid) < k) l = mid + 1;
                else r = mid - 1;
            }
            give_answer(l);
            return 0;
        } 
    }
}