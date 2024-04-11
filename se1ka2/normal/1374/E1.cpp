#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<ll>> quea, queb, qued;
    for(int i = 0; i < n; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(a & b) qued.push(t);
        else if(a) quea.push(t);
        else if(b) queb.push(t);
    }
    ll ans = 0;
    int i = 0;
    while(i < k){
        if(qued.empty()){
            if(quea.empty() || queb.empty()) break;
            else{
                ans += quea.top() + queb.top();
                quea.pop();
                queb.pop();
            }
        }
        else{
            if(quea.empty() || queb.empty() || quea.top() + queb.top() > qued.top()){
                ans += qued.top();
                qued.pop();
            }
            else{
                ans += quea.top() + queb.top();
                quea.pop();
                queb.pop();
            }
        }
        i++;
    }
    if(i < k) cout << -1 << endl;
    else cout << ans << endl;
}