#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<P> que;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            que.push(P(a, i));
        }
        vector<P> ans;
        while(true){
            P p = que.top();
            que.pop();
            P q = que.top();
            que.pop();
            if(q.first == 0) break;
            ans.push_back(P(p.second, q.second));
            p.first--;
            q.first--;
            que.push(p);
            que.push(q);
        }
        cout << ans.size() << endl;
        for(P p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}