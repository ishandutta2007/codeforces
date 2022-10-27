#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N=400000+10;
int nn,a[N];
vector<int> v[N];
int sum[N],sum2[N];
map<int,int> mp;
map<int,int> f[N];
int main() {
    scanf("%d",&nn);
    for(int i=1;i<=nn;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    for(auto p: mp) {
        v[p.second].push_back(p.first);
    }
    sum[N-1]=0;
    for(int i=N-2;i>=0;i--) sum[i]=sum[i+1]+v[i].size();
    sum2[0]=0;
    for(int i=1;i<N;i++)sum2[i]=sum2[i-1]+v[i].size() * i;
    LL ans=0;

    int n,m;
    for(int i=1;i<=nn;i++){
        //printf("i = %d, # %lld\n", i, ((sum[i]*i+sum2[i-1])/i));
        if(((sum[i]*i+sum2[i-1])/i) < i) continue;
        if(i*((sum[i]*i+sum2[i-1])/i)>=ans){
            ans=i*((sum[i]*i+sum2[i-1])/i);
            n=i,m=((sum[i]*i+sum2[i-1])/i);
        }
    }
    //printf("# %lld\n", ans);
    int x=1,y=1,done=0;
    vector<int> res;
    for(int i=n;i<N;i++){
        for(auto p: v[i]) {
            for(int j=1;j<=n;j++){
                if(done==n*m) break;
                res.push_back(p); done++;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(auto p: v[i]) {
            for(int j=1;j<=i;j++){
                if(done==n*m) break;
                res.push_back(p); done++;
            }
        }
    }
    for(int i=0,c=1;i<res.size();c++){
        int x=1,y=c;
        for(int j=i;j<i+n;j++){
            f[x][y]=res[j];
            x++,y++;
            if(x==n+1)x=1;
            if(y==m+1)y=1;
        }
        i=i+n;
    }
    printf("%d\n", ans);
    printf("%d %d\n", n, m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ", f[i][j]);
        }
        printf("\n");
    }
}