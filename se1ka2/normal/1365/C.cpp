#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200005], b[200005];
    int p[200005], q[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
        q[b[i]] = i;
    }
    int e[200005]{0};
    for(int i = 0; i < n; i++) e[(p[i] - q[i] + n) % n]++;
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, e[i]);
    cout << ans << endl;
}