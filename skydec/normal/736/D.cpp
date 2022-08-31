#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef bitset<2002> bit;
const int N=2010;
bit a[N];
bit b[N];
int n,m;
int dx[510000],dy[510000];
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&dx[i],&dy[i]);
        a[dx[i]][dy[i]]=1;
    }
    rep(i,1,n)b[i][i]=1;
    rep(i,1,n){
        int gt=0;
        rep(j,i,n)if(a[j][i]){gt=j;break;}
        swap(a[i],a[gt]);
        swap(b[i],b[gt]);
        rep(j,1,n)if(i^j)if(a[j][i]){
            a[j]^=a[i];
            b[j]^=b[i];
        }
    }
    rep(i,1,m)if(b[dy[i]][dx[i]])printf("NO\n");
    else printf("YES\n");
    return 0;
}