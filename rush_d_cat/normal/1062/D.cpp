#include <iostream>
using namespace std;
typedef long long LL;
const int N=100000+10;
int par[N]; int n; LL sum[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int main() {
    for(int i=1;i<N;i++)par[i]=i;
    scanf("%d",&n);

    for(int i=2;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            if(find(i)!=find(j)) {
                sum[find(j)] += sum[find(i)];
                par[find(i)] = find(j);
            }
            sum[find(j)] += j/i;
        }
    }
    LL ans=0;
    for(int i=2;i<=n;i++)ans=max(ans,sum[i]);
    cout<<4*ans<<endl;
}