#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int Inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int curr = Inf, x = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] - x > curr){
                a[i] -= curr;
                x = a[i];
            }
            else if(a[i] < x){
                break;
            }
            else{
                curr = a[i] - x;
                a[i] = x;
            }
        }

        /*cout << "a: ";
        for(int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << "\n";*/

        curr = Inf;
        bool ok = true;
        for(int i = n - 1; i >= 0; --i){
            if(a[i] > curr){
                ok = false;
                break;
            }
            curr = a[i];
            a[i] = 0;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}