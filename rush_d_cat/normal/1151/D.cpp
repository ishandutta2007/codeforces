#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
struct Item {
    int a,b;
    bool operator<(const Item&o)const{
        return a-b>o.a-o.b;
    }
} it[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&it[i].a,&it[i].b);
    }
    sort(it+1,it+1+n);
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+1LL*it[i].a*(i-1)+1LL*it[i].b*(n-i);
    }
    cout<<ans<<endl;
}