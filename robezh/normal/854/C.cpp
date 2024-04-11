#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

priority_queue<P> pque;

int c[300050];
int t[300050];


int main() {
    int n,k;
    long long res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

    for(int i = 1; i <= k; i++) pque.push(P(c[i],i));
    int pos = k+1;
    while(!pque.empty()){
        if(pos <= n) pque.push(P(c[pos],pos));
        P p = pque.top(); pque.pop();
        res += (ll)p.first * (pos - p.second);
        t[p.second] = pos;
        pos++;
    }
    cout << res << endl;
    for(int i = 1; i <= n; i++){
        printf("%d ", t[i]);
    }
}