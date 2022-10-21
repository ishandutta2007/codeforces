#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, sqr = 317;

int n,m,x,l,r,k,ans = 0;
int num[N];
deque<int> bk[sqr + 5];
int cnt[sqr+5][N];

//list<int>::iterator get_it(int buk, int k){
//    if(k <= bk[buk].size() / 2){
//        auto it = bk[buk].begin();
//        for(int i = 0; i < k; i++) it++;
//        return it;
//    }
//    else{
//        auto it = bk[buk].end();
//        for(int i = bk[buk].size(); i > k; i--) it--;
//        return it;
//    }
//}

int del_elt(int buk, int k){
    auto it = bk[buk].begin() + k;
    int res = *it;
    bk[buk].erase(it);
    cnt[buk][res]--;
    return res;
}

void insert_elt(int buk, int k, int val){
    auto it = bk[buk].begin() + k;
    bk[buk].insert(it, val);
    cnt[buk][val]++;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    for(int i = 0; i < n; i++){
        bk[i/sqr].push_back(num[i]);
        cnt[i/sqr][num[i]]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &x, &l, &r);
        l = (l - 1 + ans) % n; r = (r - 1 + ans) % n;
        if(l > r){
            int tmp = l; l = r, r = tmp;
        }
        if(x == 1){
            if(l == r) continue;
            int now = del_elt(r/sqr, r - r/sqr*sqr);
            insert_elt(l/sqr, l-l/sqr*sqr, now);

            for(int j = l/sqr; j < r/sqr; j++){
                int t = bk[j].back(); bk[j].pop_back();
                cnt[j][t]--;
                bk[j+1].push_front(t);
                cnt[j+1][t]++;
            }
        }
        else{
            scanf("%d", &k);
            k = (k + ans - 1) % n + 1;
            ans = 0;
            if(l / sqr == r/ sqr){
                for(int j = l; j <= r; j++){
                    ans += (bk[l/sqr][j%sqr] == k);
                }

            }
            else{
                for(int j = l % sqr; j < bk[l/sqr].size(); j++) ans += (bk[l/sqr][j] == k);
                for(int j = l/sqr+1; j < r/sqr; j++) ans += cnt[j][k];
                for(int j = 0; j <= r % sqr; j++) ans += (bk[r/sqr][j] == k);

            }
            printf("%d\n", ans);
        }
    }
}