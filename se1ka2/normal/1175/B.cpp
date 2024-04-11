#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll over = 1;
    for(int i = 0; i < 32; i++) over *= 2;
    ll l[100002];
    int c = 0;
    ll ans = 0;
    vector<int> v;
    bool f = true;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "for"){
            int k;
            cin >> k;
            if(k == 1) v.push_back(c);
            else{
                l[c] = k;
                c++;
            }
        }
        if(s == "end"){
            if((int)v.size() > 0 && v[(int)v.size() - 1] == c) v.pop_back();
            else c--;
        }
        if(s == "add"){
            ll p = 1;
            for(int j = 0; j < c; j++){
                p *= l[j];
                if(p >= over){
                    f = false;
                    break;
                }
            }
            if(f) ans += p;
            if(ans >= over){
                f = false;
                break;
            }
        }
        if(!f) break;
    }
    if(ans >= over || !f) cout << "OVERFLOW!!!" << endl;
    else cout << ans << endl;
}