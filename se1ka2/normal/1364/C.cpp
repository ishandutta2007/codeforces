#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    int b[100005];
    fill(b, b + n + 1, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]] = i;
    }
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i <= n; i++){
        if(b[i] == -1) que.push(i);
    }
    int k = 0;
    while(b[k] == -1) k++;
    for(int i = 0; i < n; i++){
        if(i > b[k]){
            que.push(k);
            k++;
            while(b[k] == -1) k++;
        }
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
}