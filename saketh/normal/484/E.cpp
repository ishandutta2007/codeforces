#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg{
    int len, left, right, big;
    seg operator+(const seg &y) const{
        struct seg res(0, len + y.len);
        res.left = left + ((left==len)?y.left:0);
        res.right = y.right + ((y.right==y.len)?right:0);
        res.big = max(max(big, y.big), right + y.left);
        return res;
    }
    seg(bool v = 1, int len = 1){
        this->len = len, left = v, right = v, big = v;
    }
};

int N, Q, L, R, W;
pair<int, int> fence[100005];

vector<struct seg> tree[(1<<18)+5];
vector<int> upd[(1<<18)+5];

struct seg read(int loc, int wid, int h){
    if(!upd[loc].size() || upd[loc][0] < h) return seg(0, wid);
    auto it = --upper_bound(upd[loc].begin(), upd[loc].end(), h, std::greater<int>());
    return tree[loc][it - upd[loc].begin()];
}

void ins(int h, int i, int loc = 1, int x = 0, int y = (1<<17)-1){
    if(i<x || i>y) return;
    upd[loc].push_back(h);
    if(x==y){ tree[loc].push_back(seg()); return; }
    int hw = (y-x+1)/2;    
    ins(h, i, 2*loc, x, x+hw-1);
    ins(h, i, 2*loc+1, x+hw, y);
    tree[loc].push_back(read(2*loc, hw, h) + read(2*loc+1, hw, h));
}

struct seg que(int h, int l, int r, int loc = 1, int x = 0, int y = (1<<17)-1){
    int wid = y-x+1;
    if(r<x || l>y) return seg(0, wid);
    if(l<=x && y<=r) return read(loc, wid, h); 
    return que(h, l, r, 2*loc, x, x+wid/2-1)
         + que(h, l, r, 2*loc+1, x+wid/2, y);
}



int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> fence[i].first;
        fence[i].second = i;
    }

    sort(fence, fence+N);
    for(int i=N-1; i>=0; i--)
        ins(fence[i].first, fence[i].second);

    for(cin >> Q; Q; Q--){
        cin >> L >> R >> W; L--, R--;
        int ans = 1;
        for(int lo=0, hi=N-1; lo<=hi; ){
            int mi = (hi+lo)/2;
            if(que(fence[mi].first, L, R).big >= W){
                ans = fence[mi].first;
                lo = mi+1;
            }
            else hi = mi-1;
        }
        cout << ans << "\n";
    }

    cout.flush();
    return 0;
}