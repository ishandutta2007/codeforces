#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string s[300005];
ll d[300005]{0}, e[300005]{0};

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i][0] == '('){
            int h = 0;
            bool f = true;
            for(int j = 0; j < (int)s[i].size(); j++){
                if(s[i][j] == '(') h++;
                else h--;
                if(h < 0){
                    f = false;
                    break;
                }
            }
            if(f) d[h]++;
        }
        if(s[i].back() == ')'){
            int h = 0;
            bool f = true;
            for(int j = (int)s[i].size() - 1; j >= 0; j--){
                if(s[i][j] == ')') h++;
                else h--;
                if(h < 0){
                    f = false;
                    break;
                }
            }
            if(f) e[h]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 300000; i++){
        ans += d[i] * e[i];
    }
    cout << ans << endl;
}