#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500, LOGN = 19;
typedef pair<int, int> P;

int n;
int ST[LOGN + 1][N], num[N];
vector<int> res;
int ld2[LOGN];

int gcd(int x, int y){
    return x == 0 ? y : gcd(y % x, x);
}

bool check(int wid){
    int step = 31 - __builtin_clz(wid);
    res.clear();

    deque<P> que;
    for(int i = 0; i < wid - 1; i++){
        while(!que.empty() && que.back().first >= num[i]) que.pop_back();
        que.push_back({num[i], i});
    }
    for(int i = wid - 1; i < n; i++){
        while(!que.empty() && que.back().first >= num[i]) que.pop_back();
        que.push_back({num[i], i});
        while(que.front().second <= i - wid) que.pop_front();
        int mn = que.front().first;
        int cgcd = gcd(ST[step][i - wid + 1], ST[step][i - (1 << step) + 1]);
        if(cgcd % mn == 0) res.push_back(i - wid + 1);
    }
    return res.size() > 0;
}

int main(){
//    for(int i = 0; i <= 4; i++){
//        cout << 31 - __builtin_clz(i) << endl;
//    }

    int pw = 1;
    for(int i = 0; i < LOGN; i++){ ld2[i] = __builtin_clz(pw); pw *= 2;}

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++) ST[0][i] = num[i];
    pw = 1;
    for(int i = 1; i < LOGN; i++){
        for(int j = 0; j + 2 * pw <= n; j++){
            ST[i][j] = gcd(ST[i-1][j], ST[i-1][j + pw]);
        }
        pw *= 2;
    }
    //cout << ST[1][]
//    cout << check(4) << endl;
    int l = 1, r = n+1, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    check(l);
    printf("%d %d\n", res.size(), l-1);
    for(int x : res) printf("%d ", x+1);
}