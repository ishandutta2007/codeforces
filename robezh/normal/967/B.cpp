#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a,b;
ll num[100050];
priority_queue<ll> pque;
ll tot = 0;

int main() {
    scanf("%d%d%d",&n,&a,&b);
    scanf("%I64d", &num[0]);
    tot = num[0];
    for(int i = 1; i < n; i++){
        scanf("%I64d", &num[i]);
        tot += num[i];
        pque.push(num[i]);
    }
    int cnt = 0;
    while(num[0] * a < 1LL * b * tot){
        cnt ++;
        tot -= pque.top();
        pque.pop();
    }
    cout << cnt;
}