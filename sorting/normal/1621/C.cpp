#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int n;

int query(int pos){
    cout << "? " << pos << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void answer(const vector<int> &p){
    cout << "!";
    for(int i = 1; i <= n; ++i)
        cout << " " << p[i];
    cout << "\n";
    cout.flush();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> n;

        vector<int> vis(n + 1, false);
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                vector<int> t;  
                t.push_back(query(i));
                do{
                    t.push_back(query(i));
                }
                while(t.back() != t[0]);

                for(int x: t)
                    vis[x] = true;

                for(int i = 0; i < (int)t.size() - 1; ++i)
                    ans[t[i]] = t[i + 1];
            }
        }

        answer(ans);
    }
    
}