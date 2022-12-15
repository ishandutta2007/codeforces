#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, n;
    cin >> a >> b >> n;

    for(int i = 0; i < 10; ++i){
        int nw = 10 * a + i;
        if(nw % b == 0){
            cout << nw;
            while(--n) cout << "0";
            return 0;
        }
    }
    cout << "-1\n";
}