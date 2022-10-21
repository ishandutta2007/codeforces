#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll pw10[16];

int main(){
    cin >> n;
    pw10[0] = 1;
    for(int i = 1; i < 16; i++) pw10[i] = pw10[i - 1] * 10;
    for(int i = 0; i < 16; i++) pw10[i] --;
    int cur = 0;
    while(pw10[cur] <= n) cur++;
    cur--;


    int res = 9 * cur;
    n -= pw10[cur];
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    cout << res << endl;
}