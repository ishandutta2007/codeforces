#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int a[500003];
bool b[500003];

int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    priority_queue<int> que;
    que.push(-1);
    for(int i = k - 1; i < n; i++){
        if(a[que.top() + 1] + d >= a[i]) b[i] = true;
        if(b[i - (k - 1)]) que.push(i - (k - 1));
    }
    if(b[n - 1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}