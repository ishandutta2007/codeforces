#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int c[100002];

int main()
{
    int n;
    cin >> n;
    int a[100002];
    int b[100002];
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            b[s] = i;
            s += a[i];
        }
    }
    if(s == 1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    int ss = s;
    for(int i = 2; i <= n; i++){
        if(ss % i == 0){
            v.push_back(i);
            while(ss % i == 0) ss /= i;
        }
    }
    ll ans = 100000000000000000;
    for(int p : v){
        ll sum = 0;
        for(int i = 0; i < s / p; i++){
            ll les = 100000000000000000;
            ll r = 0;
            for(int j = 0; j < p; j++){
                r += abs(b[i * p + j] - b[i * p + p / 2 - 1]);
            }
            les = min(les, r);
            r = 0;
            for(int j = 0; j < p; j++){
                r += abs(b[i * p + j] - b[i * p + p / 2]);
            }
            les = min(les, r);
            sum += les;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}