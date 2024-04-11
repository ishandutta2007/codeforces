#include <iostream>
using namespace std;
typedef long long LL;
int n,m;
LL c[1002];

int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int tmp=i*i%m; if(tmp==0)tmp=m;
        c[tmp]++;
    }
    for(int i=1;i<=m;i++){
        c[i] *= (n/m);
    }

    for(int i=1;i<=n%m;i++){
        int tmp=i*i%m; if(tmp==0)tmp=m;
        c[tmp] ++;
    }
    LL ans=0;
    for(int i=1;i<m;i++) ans+=c[i]*c[m-i];
    ans+=c[m]*c[m];
    cout<<ans<<endl;
}