#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;
const int Q = 2e5 + 3;

int n, m, q;
string s[N];
bool b[N];
int pr[N];

int get_sum(int l, int r){
    --r;
    if(l > r) return 0;
    if(!l) return pr[r];
    return pr[r] - pr[l - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    
    for(int i = 0; i < m - 1; ++i){
        for(int j = 1; j < n; ++j){
            if(s[j][i] == 'X' && s[j - 1][i + 1] == 'X'){
                b[i] = true;
                break;
            }
        }
    }

    pr[0] = b[0];
    for(int i = 1; i < m - 1; ++i)
        pr[i] = pr[i - 1] + b[i];

    cin >> q;
    for(int i = 0; i < q; ++i){
        int x1, x2;
        cin >> x1 >> x2;
        --x1, --x2;
        cout << (get_sum(x1, x2) ? "NO" : "YES") << "\n";
    }
}