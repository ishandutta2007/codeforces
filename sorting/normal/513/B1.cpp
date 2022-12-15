#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 8 + 3;

int n, m, perm[N], mx;

int get_score(){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int mn = perm[i];
        for(int j = i; j < n; ++j){
            check_min(mn, perm[j]);
            ans += mn;
        }
    }
    return ans;
}

bool check(){
    return get_score() == mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        perm[i] = i + 1;

    mx = -1;
    do{
        check_max(mx, get_score());
    }while(next_permutation(perm, perm + n));

    int cnt = 0;
    do{
        if(check())
            ++cnt;
        if(cnt == m){
            for(int i = 0; i < n; ++i)
                cout << perm[i] << " ";
            cout << "\n";
            return 0;
        }
    }while(next_permutation(perm, perm + n));
}