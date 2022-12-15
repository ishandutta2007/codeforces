#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        bool one = false;
        vector<int> v(n);
        for(int &x: v){
            cin >> x;
            if(x == 1)
                one = true;
        }
        sort(all(v));

        if(!one){
            cout << "Yes\n";
            continue;
        }

        bool ok = true;
        for(int i = 0; i < n - 1; ++i)
            if(v[i] == v[i + 1] - 1){
                ok = false;
                break;
            }

        cout << ((ok) ? "Yes" : "No") << "\n";
    }
}