#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int MAXV = 200005;

int bit[MAXV];
int read(int k){
    int sum = 0;
    while(k > 0){ sum += bit[k]; k -= (k & -k); }
    return sum;
}
void update(int i, int v){
    while(i < MAXV){ bit[i]+=v; i += (i & -i); }
}

int N, Q, xc[MAXV], ht[MAXV], ans[MAXV];
vector<pair<int, int> > que[MAXV];
map<int, pair<int, int> > left, right;

void ins(int x, int y, int i){
    for(auto it = left.begin(); it != left.end(); left.erase(it++)){
        if(it->first > y) break;
        y = max(y, it->second.first);
        update(it->second.second, it->first-it->second.first);
        right.erase(it->second.first);
    }
    update(i+1, y-x);
    left[x] = make_pair(y, i+1);
    right[y] = make_pair(x, i+1);
}

int read(int x, int y){
    auto it = right.upper_bound(y);
    return max(0, y - it->second.first) + read(it->second.second-1);    
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d %d", &xc[i], &ht[i]);
    
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        que[l].emplace_back(r, i);
    }

    for(int j=N-1; j>=0; j--){
        ins(xc[j], xc[j]+ht[j], j);
        for(pair<int, int> q: que[j]){
            int l = xc[j], r = xc[q.first];
            ans[q.second] = r-l-read(l, r);
        }
    }

    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}