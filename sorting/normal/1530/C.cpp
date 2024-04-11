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

        vector<int> a(n), b(n);
        for(int &x: a)
            cin >> x;
        for(int &x: b)
            cin >> x;

        sort(all(a));
        sort(all(b));

        int l = 0, r = n;
        while(l != r){
            int mid = (l + r) >> 1;
            int sum_a = 0, sum_b = 0;
            for(int i = (n + mid) / 4; i < n; ++i)
                sum_a += a[i];
            sum_a += mid * 100;
            int curr = (n + mid) / 4;
            if(curr <= mid){
                for(int i = 0; i < n; ++i)
                    sum_b += b[i];
            }
            else{
                for(int i = curr - mid; i < n; ++i)
                    sum_b += b[i];
            }
        
            if(sum_a >= sum_b) r = mid;
            else l = mid + 1;
        }

        cout << l << "\n";
    }
}