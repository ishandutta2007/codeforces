#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll m[500005];
    for(int i = 0; i < n; i++) cin >> m[i];
    ll l = 0;
    ll ans[1002];
    for(int i = 0; i < n; i++){
        ll d[1002];
        d[i] = m[i];
        for(int j = i - 1; j >= 0; j--) d[j] = min(m[j], d[j + 1]);
        for(int j = i + 1; j < n; j++) d[j] = min(m[j], d[j - 1]);
        ll s = 0;
        for(int j = 0; j < n; j++) s += d[j];
        if(s > l){
            l = s;
            for(int j = 0; j < n; j++) ans[j] = d[j];
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}