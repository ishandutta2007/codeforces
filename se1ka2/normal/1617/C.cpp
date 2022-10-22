#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        int b[100005]{0};
        priority_queue<int> que;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] <= n && !b[a[i]]) b[a[i]] = true;
            else que.push(a[i]);
        }
        int t = n;
        while(b[t]) t--;
        int ans = que.size();
        while(que.size()){
            int x = que.top();
            que.pop();
            if((x - 1) / 2 < t) break;
            b[t] = true;
            while(b[t]) t--;
        }
        if(t) cout << -1 << endl;
        else cout << ans << endl;
    }
}