#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    ll n, q;
    cin >> n >> q;
    ll t[100002];
    P p[100002];
    for(int i = 0; i < n; i++){
        scanf("%lld", &t[i]);
        p[i] = P(t[i], i);
    }
    sort(p, p + n);
    p[n] = P(100000000000000000, -1);
    ll ans[100002];
    int left = 10000000;
    ll nowt = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    int now = 0;
    while(true){
        if(p[now].first <= nowt){
            if(p[now].second < left){
                nowt += q;
                ans[p[now].second] = nowt;
                left = p[now].second;
            }
            else que.push(p[now].second);
            now++;
        }
        else{
            if(que.empty()){
                nowt = p[now].first + q;
                ans[p[now].second] = nowt;
                left = p[now].second;
                now++;
            }
            else{
                nowt += q;
                ans[que.top()] = nowt;
                left = que.top();
                que.pop();
            }
        }
        if(que.empty() && now == n) break;
    }
    for(int i = 0; i < n; i++) printf("%lld ", ans[i]);
    cout << endl;
}