#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 500;


int n;
ll k, x[N], y[N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    ll cur_x = 0, cur_y = 0;
    for(int i = 0; i < n; i++){
        ll nxt_x = -1, nxt_y = -1;
        if(y[i] == x[i]){
            if(k >= 2 && x[i] >= 2) nxt_x = nxt_y = 1;
            else {
                if(cur_y != -1 || cur_x + 1 <= k) nxt_y = 1;
                else nxt_y = -1;
                if(cur_x != -1 || cur_y + 1 <= k) nxt_x = 1;
                else nxt_x = -1;
            }
        }
        else if(y[i] > x[i]){
            if(cur_x != -1) cur_y = 0;
            ll lim = (x[i] - 1) * k + (k - cur_y);
            if(y[i] <= lim) nxt_x = 1, nxt_y = 1;
            else if(y[i] <= lim + k) nxt_y = y[i] - lim;
        }
        else{
            if(cur_y != -1) cur_x = 0;
            ll lim = (y[i] - 1) * k + (k - cur_x);
            if(x[i] <= lim) nxt_y = 1, nxt_x = 1;
            else if(x[i] <= lim + k) nxt_x = x[i] - lim;
        }
        cur_x = nxt_x;
        cur_y = nxt_y;
//        cout << cur_x << " " << cur_y << endl;
        if(cur_x == -1 && cur_y == -1) return !printf("NO");
    }
    printf("YES");
}