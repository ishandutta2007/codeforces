#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

int n, a[N], b[N];
bool vis[N];
vector<int> v;
deque<int> imp, not_imp;

void solve(){
    v.clear();
    imp.clear(), not_imp.clear();
    //cout << imp.size() << " " << not_imp.size() << endl;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    fill(vis + 1, vis + 1 + n, false);

    for(int i = 1; i <= n; ++i){
        if(!vis[a[i]]){
            b[i] = a[i];
            vis[a[i]] = true;
        }
        else{
            b[i] = -1;
            v.push_back(i);
        }
    }

    for(int x: v)
        if(!vis[x])
            imp.push_back(x);

    for(int i = 1; i <= n; ++i)
        if(!vis[i] &&  b[i] != -1)
            not_imp.push_back(i);

    if(v.empty()){
        cout << n << "\n";
        for(int i = 1; i <= n; ++i)
            cout << b[i] << " ";
        cout << "\n";
        return;
    }

    if(v.size() == 1 && !imp.empty()){
        for(int i = 1; i <= n; ++i)
            if(b[i] == a[v[0]]){
                b[v[0]] = b[i];
                b[i] = v[0];
                break;
            }

        cout << n - 1 << "\n";
        for(int i = 1; i <= n; ++i)
            cout << b[i] << " ";
        cout << "\n";
        return;
    }

    cout << n - v.size() << "\n";
    for(int x: v){
        if(imp.empty()){
            b[x] = not_imp.back();
            not_imp.pop_back();
            continue;
        }
        if(imp.front() == x){
            if(imp.size() == 1){
                b[x] = not_imp.back();
                not_imp.pop_back();
            }
            else{
                b[x] = imp.back();
                imp.pop_back();
            }
        }
        else{
            b[x] = imp.front();
            imp.pop_front();
        }
    }

    for(int i = 1; i <= n; ++i)
        while(b[i] == i);

    for(int i = 1; i <= n; ++i)
        cout << b[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}