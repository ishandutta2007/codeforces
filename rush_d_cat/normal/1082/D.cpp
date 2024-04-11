#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 500 + 10;
vector< pair<int,int> > vec;
int n,a[N];
struct Nod{
    int deg,id;
    bool operator<(const Nod&o)const{
        return deg<o.deg;
    }
} nod[N];

int dis() {
    int f[N][N];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)
        f[i][j]=i==j?0:1e9;

    for(auto p: vec){
        f[p.first][p.second]=f[p.second][p.first]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        ans=max(ans,f[i][j]);
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&nod[i].deg);nod[i].id=i;
    }
    sort(nod+1,nod+1+n);
    int now=n;

    int lim=0;
    for(int i=n;i>=1;i--){
        if(nod[i].deg==1){
            lim=i; break;
        }
    }

    for(int i=n-2;i>=1;i--){
        if(nod[i].deg>=2){
            vec.push_back(make_pair(nod[now].id,nod[i].id));
            nod[i].deg --; nod[now].deg --;
            now=i;
        } else{
            break;
        }
    }
    if(nod[n-1].deg>=2){
        vec.push_back(make_pair(nod[now].id,nod[n-1].id));
        nod[n-1].deg--; nod[now].deg--;
    }
    //printf("! %d\n", vec.size());
    for(int i=1;i<=lim;i++){
        if(i==1)
            vec.push_back(make_pair(nod[i].id, nod[n].id)),nod[n].deg--;
        else if(i==2 && lim<=n-2)
            vec.push_back(make_pair(nod[i].id, nod[n-1].id)),nod[n-1].deg--;
        else {
            bool ok=0;
            for(int j=lim+1;j<=n;j++) {
                if(nod[j].deg>=1){
                    ok=1;
                    nod[j].deg--; vec.push_back(make_pair(nod[i].id,nod[j].id)); break;
                }
            }
            if(ok==0) {
                return !printf("NO\n");
            }
        }
    }

    printf("YES %d\n", dis());
    printf("%d\n", vec.size());
    for(int i=0;i<vec.size();i++)
        printf("%d %d\n", vec[i].first,vec[i].second);
}