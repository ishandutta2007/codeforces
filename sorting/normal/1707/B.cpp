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

        auto count_nz = [&](const vector<int> &a){
            int cnt = 0;
            for(int x: a)
                if(x)
                    ++cnt;
            return cnt;
        };

        while(count_nz(a) > 2){
            // cout << "a: ";
            // for(int x: a)
                // cout << x << " ";
            // cout << endl;

            vector<int> b(a.size() - 1);
            for(int i = 0; i < a.size() - 1; ++i)
                b[i] = a[i + 1] - a[i];
            sort(all(b));
            swap(a, b);
        }

        function<int(int, int, int)> f = [&](int x, int y, int num){
            if(!y)
                return x;
            if(x / y >= num){
                return x - y * num;
            }
            return f(y, x % y, num - x / y);
        };

        if(a.size() == 1)
            cout << a[0] << "\n";
        else
            cout << f(a.back(), a[a.size() - 2], a.size() - 1) << "\n";
    }
}