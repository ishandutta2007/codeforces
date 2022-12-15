#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int n;

int query(const vector<int> &a){
    cout << "? ";
    for(int x: a)
        cout << x << " ";
    cout << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void answer(const vector<int> &v){
    cout << "! ";
    for(int x: v)
        cout << x << " ";
    cout << "\n";
    cout.flush();
    exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> v, a(n);
    for(int i = n - 1; i >= 1; --i){
        for(int j = 0; j < n - 1; ++j)
            a[j] = 1 + i;
        a[n - 1] = 1;
        v.push_back(query(a));
    }
    for(int i = 1; i <= n - 1; ++i){
        for(int j = 0; j < n - 1; ++j)
            a[j] = 1;
        a[n - 1] = 1 + i;
        v.push_back(query(a));
    }

    vector<int> ans(n);
    for(int i = 0; i < 2 * n - 2; ++i)
        --v[i];
    for(int i = 0; i < 2 * n - 2; ++i){
        if(v[i] != -1){
            ans[n - 1] = n - i;
            break;
        }
    }

    for(int i = 0; i < 2 * n - 2; ++i){
        if(v[i] == -1) continue;
        if(i < n - 1){
            ans[v[i]] = ans[n - 1] - (n - 1 - i);
        }
        else{
            ans[v[i]] = ans[n - 1] + (i - (n - 2));
        }
    }
    
    answer(ans);
}