#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int num[100050];
ll psum[100050], pre[100050];


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    int cur = 0;
    ll res = 0;
    for(int i = 0; i < n; i++){
        //cout << "i = " << i << endl;
        if(num[i] >= cur){
            cur = num[i]+1;
        }
        else{
            res += (cur - 1 - num[i]);
        }
        pre[i] = cur;
        psum[i] = (i == 0 ? pre[i] : pre[i] + psum[i-1]);
        //if(cur == num[i] + 1) res += calc(i, cur);
        //cout << "i = " << i << ", res = " << res << endl;
        //cout << psum[i] << " ";
    }
    cur = pre[n-1];
    for(int i = n-1; i >= 0; i--){
        if(i != n-1) cur = max(cur-1, (int)pre[i]);
        res += (cur - pre[i]);
    }

    cout << res;
}