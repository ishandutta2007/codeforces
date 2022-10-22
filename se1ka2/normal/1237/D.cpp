#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int a[300002];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i];
        a[i + n * 2] = a[i];
    }
    priority_queue<P> que;
    que.push(P(a[0], 0));
    int last = 0;
    int ans[300002];
    for(int i = 1; i < n * 3; i++){
        que.push(P(a[i], i));
        while(a[i] * 2 < que.top().first){
            for(; last <= que.top().second; last++) ans[last] = i - last;
            que.pop();
        }
    }
    if(last == 0){
        for(int i = 0; i < n; i++) cout << -1 << " ";
    }
    else{
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
    }
    cout << endl;
}