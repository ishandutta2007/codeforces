#include<bits/stdc++.h>
using namespace std;
int a[200005][6],mx,n;
bool calc(int x, int y){
    int cnt = 0;
    for (int i = 1; i <= 5; i++)  if(a[x][i] > a[y][i]) cnt++;
    return cnt >= 3;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++) cin >> a[i][j];
    int mx = 1;
    for (int i = 2; i <= n; i++) if (calc(mx, i))   mx=i;
    bool ok=1;
    for (int i = 1; i <= n; i++) if(i != mx) if(calc(mx, i))   ok=0;
    if (!ok) 
        puts("-1");
    else 
        cout << mx << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}