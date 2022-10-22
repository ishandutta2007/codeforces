#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int p[200005], q[200005];
    int  rq[200005];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; i++){
        cin >> q[i];
        q[i]--;
        rq[q[i]] = i;
    }
    char c[200005];
    char now = 'a';
    int to = 0;
    for(int i = 0; i < n; i++){
        c[p[i]] = now;
        to = max(to, rq[p[i]]);
        if(i == to && now != 'z') now++;
    }
    if(now == 'z') now++;
    if(now - 'a' >= k){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) cout << c[i];
    }
    else cout << "NO" << endl;
}