#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define hw (y - x + 1)/2
using namespace std;

typedef long long ll;
const int INF = 0x7f7f7f7f;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

struct seg_tree{
    struct node{
        int val;
        node(int _val = 0x7f7f7f7f){ 
            val = _val; 
        }
        node operator +(const node &y){
            return min(val, y.val);
        }
    };

    int S;
    vector<node> arr;
    seg_tree(int _S){
        S = _S;
        arr.resize(2*S+1);
    }

    void upd(int i, node v){
        i += S;
        arr[i] = v;
        while(i>1){
            i/=2;
            arr[i] = arr[2*i] + arr[2*i+1];
        }
    }

    node query(int i, int j){
        node res; 
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res = res + arr[i++];
            if((j&1) == 0) res = res + arr[j--];
        }
        return res;
    }
};

// find the biggest index <= i such that [i, j] has val <= K
int find(seg_tree &seg, int i, int k){
    int lo = 0, hi = i;
    int ans = 0;

    while(lo <= hi){
        int mi = (lo + hi) / 2;
        int lv = seg.query(mi, i).val;
        if(lv <= k){
            ans = mi;
            lo = mi+1;
        }
        else hi = mi-1;
    }

    return ans;
}

int look(vector<int> &all, int v){
    return lower_bound(all.begin(), all.end(), v) - all.begin();
}

const int MAXQ = 200005;

int N, Q;

int L[MAXQ], LC[MAXQ];
int R[MAXQ], RC[MAXQ];
char T[MAXQ];

vector<bool> ater, atec;

int main(){
    setup();
    cin >> N >> Q;

    vector<int> all;
    all.push_back(0);
    for(int i=0; i<Q; i++){
        cin >> L[i] >> R[i] >> T[i];
        all.push_back(L[i]);
        all.push_back(R[i]);
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    ater.resize(all.size());
    atec.resize(all.size());
   
    int ts = all.size();

    seg_tree rows(ts), cols(ts);
    rows.upd(0, 0);
    cols.upd(0, 0);

    for(int i=0; i<Q; i++){
        int LC = look(all, L[i]);
        int RC = look(all, R[i]);

        if(T[i] == 'U'){
            if(atec[LC] || ater[RC]){
                cout << 0 << "\n";
                continue;
            }
            int b = find(rows, RC, LC);           
            cols.upd(LC, b);
            cout << all[RC] - all[b] << "\n";
            atec[LC] = true;
        }
        else{
            if(ater[RC] || atec[LC]){
                cout << 0 << "\n";
                continue;
            }
            int b = find(cols, LC, RC);
            rows.upd(RC, b);
            cout << all[LC] - all[b] << "\n";
            ater[RC] = true;
        }
    }
}