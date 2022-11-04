#include <iostream>
#include <bitset>
using namespace std;
const int N = 1e6;

int n;
bitset<N> bs, ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> bs;
    int p = -1, q;
    for (int i = N - 1; i >= 0; i--){
        if(bs[i] == 1){
            if(p == -1)
                p = i;
        }
        else if(p != -1){
            q = i;
            break;
        }
    }
    ans = bs;
    for (int i = 0; i <= p - q; i++){
        bitset<N> tmp = bs | (bs >> i);
        for (int i = N - 1; i; i--){
            if(tmp[i] > ans[i]){
                ans = tmp;
                break;
            }
            else if(tmp[i] < ans[i])
                break;
        }
    }
    p = -1;
    for (int i = N - 1; i; i--)
        if(ans[i] == 1){
            p = i;
            break;
        }
    if(p == -1)
        cout << '0';
    else
        for (int i = p; i >= 0; i--)
            cout << ans[i];
    return 0;
}