#include <map>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 200005
typedef long long ll; 
using namespace std;

map<int,ll>f1,f2;

int n,k,a[MAXN];

ll ans;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;++i){
        if(a[i]%k==0){
            if((a[i]/k)%k==0){
                ans+=f2[a[i]/k/k];
            }
            f2[a[i]/k]+=f1[a[i]/k];
        }
        ++f1[a[i]]; 
    }
    printf("%I64d\n",ans);
    return 0;
}