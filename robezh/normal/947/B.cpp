#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
priority_queue<ll, vector<ll>, greater<ll> > pque;
ll v[100050], t[100050];


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%I64d", &v[i]);
    for(int i = 0; i < n; i++) scanf("%I64d", &t[i]);

    ll pv = 0, cv = 0;

    for(int i = 0; i < n; i++){
        pque.push(v[i] + cv);
        pv = cv;
        cv += t[i];
        ll res = 0;
        while(!pque.empty() && pque.top() <= cv){
            res += (pque.top() - pv);
            pque.pop();
        }
        res += t[i] * pque.size();
        printf("%I64d ", res);
    }
}