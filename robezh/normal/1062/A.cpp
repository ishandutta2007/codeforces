#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, num[N];


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];

    num[0] = 0;
    num[n+1] = 1001;

    int cnt = 1, mx = 0;
    for(int i = 1; i <= n + 1; i++){
        if(num[i] == num[i-1] + 1){
            cnt ++;
            mx = max(mx, cnt);
        }
        else cnt = 1;
    }
    mx = max(0, mx - 2);
    if(mx == n) mx --;
    cout << mx << endl;
}