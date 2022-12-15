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
        ll a, b, c;
        cin >> a >> b >> c;

        ll arr[3]{a, b, c};
        sort(arr, arr + 3);

        ll ans[3]{};

        if(arr[2] == a){
            ans[0] = a;
            ans[2] = a + c;
            ans[1] = a + b + c;
        }
        else if(arr[2] == b){
            ans[1] = b;
            ans[0] = b + a;
            ans[2] = b + a + c;
        }
        else if(arr[2] == c){
            ans[2] = c;
            ans[1] = b + c;
            ans[0] = a + b + c;
        }   

        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
}