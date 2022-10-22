#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll now = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') now++;
            else{
                if(k >= now){
                    swap(s[i], s[i - now]);
                    k -= now;
                }
                else{
                    swap(s[i], s[i - k]);
                    k = 0;
                    break;
                }
            }
        }
        cout << s << endl;
    }
}