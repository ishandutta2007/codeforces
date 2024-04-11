#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50, B = 20;
struct P{
    int l, id;
};

int n,q;
vector<P> qry[N];
int num[N];
int bas[B], sz = 0, pos[B];
int res[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r; l--, r--;
        qry[r].push_back({l, i});
    }
    for(int i = 0; i < n; i++) {
        int x = num[i];
        int nowpos = i;
        for(int j = B - 1; j >= 0; j--) {
            if(x & (1 << j)) {
                if(!bas[j]) {
                    bas[j] = x; pos[j] = nowpos;
                    break;
                }
                if(pos[j] < nowpos) {
                    swap(x, bas[j]);
                    swap(nowpos, pos[j]);
                }
                x ^= bas[j];
            }
        }
        for(auto &p : qry[i]) {
            int cur = 0;
            for(int j = B - 1; j >= 0; j--){
                if(pos[j] < p.l) continue;
                if((cur ^ bas[j]) > cur) cur ^= bas[j];
            }
            res[p.id] = cur;
        }
    }
    for(int i = 0; i < q; i++) cout << res[i] << "\n";
}