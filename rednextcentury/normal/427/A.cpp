#include <iostream>

using namespace std;

typedef long long ll;
int main()
{
    ll n; cin >> n;
    ll police = 0, ans = 0;
    int input, prev = 0;
    while(n--){
        cin >> input;
        if(input == -1){
            police --;
            if(police < 0){
                ans ++;
                police = 0;
            }
        }else{
            police += input;
        }
    }
    cout << ans;
    return 0;
}