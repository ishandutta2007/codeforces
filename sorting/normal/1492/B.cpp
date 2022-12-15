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

        vector<int> p(n);
        for(int i = 0; i < n; ++i)
            cin >> p[i];

        set<int> rem;
        for(int i = 1; i <= n; ++i)
            rem.insert(i);

        vector<int> ans;
        while(!p.empty()){
            int j;
            for(int i = (int)p.size() - 1; i >= 0; --i)
                if(p[i] == *rem.rbegin()){
                    j = i;
                    break;
                }

            for(int i = j; i < p.size(); ++i)
                ans.push_back(p[i]);

            while(p.size() > j){
                rem.erase(p.back());
                p.pop_back();
            }
        }

        for(int x: ans)
            cout << x << " ";
        cout << "\n";
    }
}