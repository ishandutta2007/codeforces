#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    int c[200005]{0};
    for(int i = 0; i < n - 1; i++){
        cin >> a[i];
        a[i]--;
        c[a[i]]++;
    }
    int l[200005];
    for(int i = 0; i < n; i++) l[i] = i;
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < n; i++) if(c[i] == 0) que.push(P(l[i], i));
    vector<P> ans(n - 1);
    for(int j = n - 2; j >= 0; j--){
        P p = que.top();
        que.pop();
        ans[j] = P(a[j], p.second);
        l[a[j]] = max(l[a[j]], p.first);
        c[a[j]]--;
        if(c[a[j]] == 0) que.push(P(l[a[j]], a[j]));
    }
    cout << a[0] + 1 << endl;
    for(int i = 0; i < n - 1; i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    cout << endl;
}