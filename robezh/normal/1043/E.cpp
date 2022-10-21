#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
const int N = (int)3e5 + 500;

int n,m;
int x[N], y[N];
ll psum_x[N], psum_y[N];
Pi ps[N];
int loc[N];
ll res[N];


bool cmp(Pi p1, Pi p2){
    return p1.first.first - p1.first.second < p2.first.first - p2.first.second;
}

ll get_score(int i, int j){
    ll res1 = x[i] + y[j], res2 = x[j] + y[i];
    return min(res1, res2);
}

int main(){
    scanf("%d%d", &n, &m);;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x[i], &y[i]);
        ps[i].first.first = x[i], ps[i].first.second = y[i];
        ps[i].second = i;
    }
    sort(ps, ps+n, cmp);
    for(int i = 0; i < n; i++) loc[i] = ps[i].second;

    psum_x[0] = x[ps[0].second];
    psum_y[0] = y[ps[0].second];
    for(int i = 1; i < n; i++){
        psum_x[i] = psum_x[i-1] + x[ps[i].second];
        psum_y[i] = psum_y[i-1] + y[ps[i].second];
    }
    for(int i = 0; i < n; i++){
        ll rsum_y = 1LL * (psum_y[n-1] - psum_y[i]) + 1LL * (n - 1 - i) * x[ps[i].second];
        ll lsum_x = 1LL * (i == 0 ? 0 : psum_x[i-1]) + (i == 0 ? 0 : 1LL * i * y[ps[i].second]);
        res[loc[i]] = rsum_y + lsum_x;
        //cout << loc[i] << ": " << i << ", " << rsum_y  <<" , " << lsum_x << endl;
     }

//    for(int i = 0; i < n; i++) cout << res[i] << " ";
//    cout << endl;

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        ll score = get_score(a, b);
        res[a] -= score;
        res[b] -= score;
    }
    for(int i = 0; i < n; i++){
        printf("%I64d ", res[i]);
    }

}