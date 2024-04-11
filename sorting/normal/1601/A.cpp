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

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        int cnt[30]{};
        for(int i = 0; i < 30; ++i){
            for(int x: a)
                if((x >> i) & 1)
                    ++cnt[i];
        }

        int gcd = 0;
        for(int i = 0; i < 30; ++i){
            if(!cnt[i]) continue;
            //cout << cnt[i] << " ";
            gcd = __gcd(gcd, cnt[i]);
        }
        //cout << "\n";

        if(!gcd){
            for(int i = 1; i <= n; ++i)
                cout << i << " ";
            cout << "\n";
        }
        else{
            for(int i = 1; i <= n; ++i)
                if(gcd % i == 0)
                    cout << i << " ";
            cout << "\n";
        }
    }
}