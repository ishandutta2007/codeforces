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
        const int N = 503;

        int n;
        cin >> n;

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        vector<pair<int, int>> v1;
        vector<int> v2;

        vector<int> added;
        int cnt = 0;
        bool ok = true;
        for(int i = 0; !a.empty(); ++i){
            // cout << "a: ";
            // for(int x: a)
                // cout << x << " ";
            // cout << endl;

            int pair = -1;
            for(int j = 1; j < a.size(); ++j){
                if(a[0] == a[j]){
                    pair = j;
                    break;
                }
            }

            if(pair == -1){
                cout << "-1\n";
                ok = false;
                break;
            }

            int new_cnt = cnt;
            for(int j = 1; j < pair; ++j){
                v1.push_back({cnt + pair + j, a[j]});
            }
            new_cnt += 2 * pair;
            v2.push_back(pair * 2);
            cnt = new_cnt;

            a.erase(a.begin() + pair);
            a.erase(a.begin());
            reverse(a.begin(), a.begin() + pair - 1);
        }

        if(!ok) continue;

        cout << v1.size() << "\n";
        for(auto [p1, p2]: v1)
            cout << p1 << " " << p2 << "\n";

        cout << v2.size() << "\n";
        for(int x: v2)
            cout << x << " ";
        cout << "\n";
    }
}