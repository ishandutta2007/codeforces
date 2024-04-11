#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000 + 10;
int n,y1,m,y2;
int a[N],b[N],vis[N];
vector<int> fac;
void getFac(int x) {
    fac.clear(); 
    for(int i=1;i*i<=x;i++) {
        if (x%i==0) {
            fac.push_back(i);
            fac.push_back(x/i);
        }
    }
    sort(fac.begin(), fac.end());
}
int main() {
    srand(time(NULL));
    scanf("%d%d",&n,&y1);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    scanf("%d%d",&m,&y2);
    for(int i=1;i<=m;i++) scanf("%d", &b[i]);

    int ans = 2;

    for(int i=1;i<=60;i++) {
        int x = 1LL*rand()*rand()%n + 1;
        int y = 1LL*rand()*rand()%m + 1;
        if (a[x] == b[y]) continue;
        int d = abs(a[x]-b[y]);
        getFac(d);
        int T=-1;
        for(auto x: fac) {
            if((d/x)%2 == 1) {
                T=x; break;
            }
        }
        if(T==-1) continue;
        int tmp=0;
        for(int j=1;j<=n;j++){
            if(a[j]%(2*T) == a[x]%(2*T)) tmp ++;
        }
        for(int j=1;j<=m;j++){
            if(b[j]%(2*T) == b[y]%(2*T)) tmp ++;
        }
        ans = max(ans, tmp);
    }

    for(int i=1;i<=60;i++) {
        int x = 1LL*rand()*rand()%n + 1;
        int y = 1LL*rand()*rand()%n + 1;
        if (a[x] == a[y]) continue;
        int d = abs(a[x]-a[y]);
        getFac(d);
        int T=-1;
        for(auto x: fac) {
            if((d/x)%2 == 0) {
                T=x; break;
            }
        }
        if(T==-1) continue;

        int tmp=0;
        for(int j=1;j<=n;j++){
            if(a[j]%(2*T) == a[x]%(2*T)) tmp ++;
        }
        for(int j=1;j<=m;j++){
            if(b[j]%(2*T) == (a[x]%(2*T)+T)%(2*T)) tmp ++;
        }
        ans = max(ans, tmp);
    }

    for(int i=1;i<=60;i++) {
        int x = 1LL*rand()*rand()%m + 1;
        int y = 1LL*rand()*rand()%m + 1;
        if (b[x] == b[y]) continue;
        int d = abs(b[x]-b[y]);
        getFac(d);
        int T=-1;
        for(auto x: fac) {
            if((d/x)%2 == 0) {
                T=x; break;
            }
        }
        if(T==-1) continue;
        int tmp=0;
        for(int j=1;j<=m;j++){
            if(b[j]%(2*T) == b[x]%(2*T)) tmp ++;
        }
        for(int j=1;j<=n;j++){
            if(a[j]%(2*T) == (b[x]%(2*T)+T)%(2*T)) tmp ++;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

}