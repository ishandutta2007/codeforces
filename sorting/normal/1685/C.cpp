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

        string s;
        cin >> s;

        n = 2 * n;

        vector<int> pr(n + 1);
        pr[0] = 0;
        for(int i = 0; i < n; ++i){
            pr[i + 1] = pr[i] + ((s[i] == '(') ? 1 : -1); 
        }

        vector<int> neg;
        for(int i = 1; i <= n; ++i)
            if(pr[i] < 0)
                neg.push_back(i);

        if(neg.empty()){
            cout << "0\n";
            continue;
        }

        pair<int, int> max1{INT_MIN, 0}, max2{INT_MIN, 0}, max3{INT_MIN, 0};
        for(int i = 0; i < neg[0]; ++i)
            check_max(max1, {pr[i], i});
        for(int i = neg[0]; i <= neg.back(); ++i)
            check_max(max2, {pr[i], i});
        for(int i = neg.back(); i <= n; ++i)
            check_max(max3, {pr[i], i});

        if(max2.first <= max1.first + max3.first){
            cout << "1\n";
            cout << max1.second + 1 << " " << max3.second << "\n";
            continue;
        }

        check_max(max1, max(max2, max3));
        cout << "2\n";
        cout << 1 << " " << max1.second << "\n";
        cout << max1.second + 1 << " " << n << "\n";
    }
}