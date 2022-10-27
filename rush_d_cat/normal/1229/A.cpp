#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,vis[N];
struct Item {
    LL a,b;
    bool operator<(const Item&o)const{
        return a<o.a;
    }
} it[N];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &it[i].a);
    }
    for(int i=1;i<=n;i++) {
        scanf("%lld", &it[i].b);
    }
    sort(it+1,it+1+n);
    LL mx = 0;
    for(int i=1,j=1;i<=n;i=j){
        while(j<=n && it[j].a == it[i].a) j++;
        if(j-i>1) {
            for(int x=i;x<j;x++){
                mx += it[x].b; vis[x]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            for(int j=1;j<=n;j++){
                if(vis[j] == 1) {
                    if( (it[i].a & it[j].a) == it[i].a ) {
                        mx += it[i].b;
                        break;
                    }
                }
            }
        }
    }
    cout << mx << endl;
}