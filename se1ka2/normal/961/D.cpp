#include <iostream>
using namespace std;
typedef long long ll;

bool same(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    if((x2 - x1) * (y3 - y2) == (x3 - x2) * (y2 - y1)) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    if(n <= 4){
        cout << "YES" << endl;
        return 0;
    }
    ll x[100002], y[100002];
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    bool b[100002]{0};
    bool f = false;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < n; k++){
                if(same(x[i], y[i], x[j], y[j], x[k], y[k])){
                    f = true;
                    b[k] = true;
                }
            }
            if(f){
                b[i] = true;
                b[j] = true;
                break;
            }
        }
        if(f) break;
    }
    if(!f){
        cout << "NO" << endl;
        return 0;
    }
    int i, j;
    for(i = 0; i < n; i++) if(!b[i]) break;
    for(j = i + 1; j < n; j++) if(!b[j]) break;
    for(int k = j + 1; k < n; k++){
        if(!b[k] && !same(x[i], y[i], x[j], y[j], x[k], y[k])){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}