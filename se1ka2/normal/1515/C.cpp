#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, x;
        cin >> n >> m >> x;
        int h[100005];
        for(int i = 0; i < n; i++) cin >> h[i];
        int ans[100005];
        priority_queue<P, vector<P>, greater<P>> que;
        for(int i = 0; i < m; i++) que.push(P(0, i));
        for(int i = 0; i < n; i++){
            P p = que.top();
            que.pop();
            ans[i] = p.second;
            p.first += h[i];
            que.push(p);
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        cout << endl;
    }
}