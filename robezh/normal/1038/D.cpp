#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 500, INF = (int)2e9;

int n;
int num[N];
int mnpos = INF, mxneg = -INF;


int main(){
    scanf("%d", &n);
    ll res = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i] >= 0){
            mnpos = min(mnpos, num[i]);
            res += num[i];
        }
        if(num[i] <= 0){
            mxneg = max(mxneg, num[i]);
            res -= num[i];
        }
    }
    if(mnpos == INF) res += 2 * mxneg;
    if(n > 1 && mxneg == -INF) res -= 2 * mnpos;

    cout << res << endl;


}