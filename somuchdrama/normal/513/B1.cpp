#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;

vector<int> cur;
vector<char> used;
int n, m, c = 1;
vector<pair<int, vector<int> > >A;
int ans = 0;

void check(){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int mn = cur[i];
        for(int j = i; j < n; ++j){
            mn = min(mn, cur[j]);
            sum += mn;
        }
    }
    if(sum == ans){
        ++c;
        if(m == c){
            A.push_back({sum, cur});
        }
    }
    if(sum > ans){
        ans = sum;
        c = 1;
        A.push_back({sum, cur});
    }
}

void gen(int k){
    if(k == n){
        check();
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(!used[i]){
            used[i] = 1;
            cur[k] = i;
            gen(k + 1);
            used[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    cur.assign(n, 0);
    used.assign(n + 1, 0);
    gen(0);
    sort(A.begin(), A.end());
//    cout << A.size();
    for(int i = 0; i < n; ++i){
        cout << A[A.size() - 1].second[i] << " ";
    }
    return 0;
}