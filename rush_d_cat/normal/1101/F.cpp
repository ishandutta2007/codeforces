#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=402;
int n,m,a[N]; LL sum[N];
vector<int> v;

int nex[N][N*N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            v.push_back(sum[j]-sum[i]);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++){
        int j=i;
        for(int k=0;k<v.size();k++) {
            while(j<=n && sum[i]+v[k]>=sum[j]) j++;
            nex[i][k]=j-1;
        }
    }
    LL ret=0;
    for(int i=1;i<=m;i++){
        int s,f,c,r; scanf("%d%d%d%d",&s,&f,&c,&r); 
        int lef=-1,rig=(int)v.size()-1;
        while(rig-lef>1){
            int mid=(lef+rig)>>1;
            int x=s,cnt=0;
            while(x<f) {
                if(x==nex[x][mid]){
                    cnt=1e9; break;
                }
                x=nex[x][mid]; cnt++;
            }
            if(cnt<=r+1) rig=mid; else lef=mid;
        }
        //printf("%d\n", v[rig]);
        ret=max(ret,1LL*v[rig]*c); 
    }
    cout<<ret<<endl;
}