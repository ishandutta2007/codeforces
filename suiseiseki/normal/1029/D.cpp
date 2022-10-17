#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map<int,int> mp[15];
const int N=2e5+5;
const long long shi[15]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
int ws(int u){
    return (int)log10(u)+1;
}
int n,k,a[N],mo[N];
long long ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mo[i]=a[i]%k;
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            mp[j][(int)(((shi[j]%k)*mo[i])%k)]++;
        }
    }
    for(int i=1;i<=n;i++){
        int w=ws(a[i]);
        ans+=mp[w][(k-mo[i])%k];
        if((int)((((shi[w]%k)*mo[i])%k)+mo[i])%k==0){
            ans--;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}