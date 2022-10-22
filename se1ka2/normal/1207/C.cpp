#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        ll d = a * 2 / b;
        int start;
        int last;
        for(start = 0; start < n; start++){
            if(s[start] == '1') break;
        }
        if(start == n){
            cout << a * n + b * (n + 1) << endl;
            continue;
        }
        for(last = n - 1; last >= 0; last--){
            if(s[last] == '1') break;
        }
        int now = 0;
        ll r = last - start + 2;
        ll h = 2;
        for(int i = start; i <= last; i++){
            if(s[i] == '0') now++;
            else{
                if(now > d + 1){
                    r -= now - 1;
                    h += 2;
                }
                now = 0;
            }
        }
        cout << (n + h) * a + (n + 1 + r) * b << endl;
    }
}