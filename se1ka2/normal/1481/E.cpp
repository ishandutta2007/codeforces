#include <iostream>
using namespace std;

int a[500005];
int l[500005];
int r[500005];
int c[500005];
int x[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++) l[i] = -1;
    for(int i = 0; i < n; i++){
        if(l[a[i]] == -1){
            l[a[i]] = i;
            r[a[i]] = i;
            c[i] = 1;
        }
        else{
            c[i] = c[r[a[i]]] + 1;
            r[a[i]] = i;
        }
    }
    x[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, x[i] + c[r[a[i]]] - c[i] + 1);
        x[i + 1] = x[i];
        if(r[a[i]] == i){
            x[i + 1] = max(x[i + 1], x[l[a[i]]] + c[r[a[i]]]);
        }
    }
    ans = max(ans, x[n]);
    cout << n - ans << endl;
}