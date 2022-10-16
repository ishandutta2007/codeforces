#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,a[200005],c[200005],sum[200005],cnt,l,r,mid;
vector<int> v[200005];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=k;++i)
        scanf("%d",c+i);
    for(int i=1;i<=n;++i){
        int t=a[i];
        l=1;r=cnt+1;
        while(l<r){
            mid=(l+r)>>1;
            if(c[t]>sum[mid])r=mid;
            else l=mid+1;
        }
        if(l>cnt){
            ++cnt;
            sum[cnt]=1;
            v[cnt].push_back(t);
            continue;
        }
        ++sum[l];
        v[l].push_back(t);
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i){
        printf("%d",v[i].size());
        for(int j=0;j<v[i].size();++j)
            printf(" %d",v[i][j]);
        printf("\n");
    }
    return 0;
}