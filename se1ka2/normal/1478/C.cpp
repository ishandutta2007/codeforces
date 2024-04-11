#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll d[200005];
        for(int i = 0; i < n * 2; i++) cin >> d[i];
        sort(d, d + n * 2, greater<ll>());
        bool f = true;
        ll s = 0;
        for(int i = 0; i < n * 2; i += 2){
            if(d[i] != d[i + 1]) f = false;
            if(i > 1 && d[i] == d[i - 1]) f = false;
            if(d[i] - s <= 0 || (d[i] - s) % (n * 2 - i)) f = false;
            s += (d[i] - s) / (n * 2 - i) * 2;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}