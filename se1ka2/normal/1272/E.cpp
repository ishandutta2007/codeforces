#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans[200005];
    fill(ans, ans + n, -1);
    queue<int> que;
    vector<int> v[200005];
    for(int i = 0; i < n; i++){
        if(i - a[i] >= 0){
            if(a[i - a[i]] % 2 != a[i] % 2){
                ans[i] = 1;
                que.push(i);
                continue;
            }
            else v[i - a[i]].push_back(i);
        }
        if(i + a[i] < n){
            if(a[i + a[i]] % 2 != a[i] % 2){
                ans[i] = 1;
                que.push(i);
            }
            else v[i + a[i]].push_back(i);
        }
    }
    while(que.size()){
        int u = que.front();
        que.pop();
        for(int w : v[u]){
            if(ans[w] == -1){
                ans[w] = ans[u] + 1;
                que.push(w);
            }
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}