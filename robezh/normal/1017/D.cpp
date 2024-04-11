#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int N = 15, M = 4096, Q = (int)5e5 + 500;

int n,m,q,x;
string s;
int w[15], cnt[M];
P cost[M];
vector<P> qry[M];
ll res[Q];

int conv(string s){
    int now = 0, mul = 1;
    for(char c : s){
        now += (c - '0') * mul;
        mul *= 2;
    }
    return now;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < (1 << n); i++){
        cost[i].second = i;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1) cost[i].first += w[j];
        }
    }
    sort(cost, cost + (1 << n));

    for(int i = 0; i < m; i++){
        cin >> s;
        cnt[conv(s)] ++ ;
    }
    for(int i = 0; i < q; i++){
        cin >> s >> x;
        //cout << conv(s) << endl;
        qry[conv(s)].push_back({x, i});
    }
    for(int i = 0; i < (1 << n); i++) sort(qry[i].begin(), qry[i].end());
    for(int i = 0; i < (1 << n); i++){
        ll cntsum[M];
        fill(cntsum, cntsum+M, 0);
        for(int j = 0; j < (1 << n); j++){
            int trans = (((1 << n) - 1) - cost[j].second) ^ i;
            cntsum[j] = cnt[trans];
            if(j != 0) cntsum[j] += cntsum[j-1];
        }
        for(P p : qry[i]){
            int loc = upper_bound(cost, cost+(1 << n), make_pair(p.first, 100000)) - cost;
            if(loc >= 1){
                loc --;
                res[p.second] = cntsum[loc];
            }
            else res[p.second] = 0;
        }
    }
    for(int i = 0; i < q; i++){
        cout << res[i] << "\n";
    }
}