//In the name of God
#include <iostream>
#include <iomanip>
using namespace std;
const int Maxn = 520;
int val[Maxn];
int main(){
    int n,m;
    cin >> n >> m;
    long double ans = 0;
    for(int i = 0; i < n;i++)
        cin >> val[i];
    for(int i = 0; i < m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        ans = max(ans,((long double)val[--u] + (long double)val[--v])/w);
    }
    cout << setprecision(9) << fixed << ans << endl;
    return 0;
}