#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;

const int Maxn=100010,INF=~0u>>1;

typedef pair<int,int> pii;
set<pii> s;
typedef set<pii>::iterator IT;
#define X first
#define Y second
#define mp make_pair

int A[Maxn],B_pos[Maxn],B[Maxn],v[Maxn];
int gt(){
    int x=0,f=1;
    char c;
    while(c=getchar(),c<48||c>57)
        if(c=='-')f=-1;
    for(;c>47&&c<58;c=getchar())
        x=x*10+c-48;
    return f*x;
}

int main(){
//  freopen("gyz_gyz.in","r",stdin);
//  freopen("gyz_gyz.out","w",stdout);
    int n=gt();
    s.insert(make_pair(INF,0));
    s.insert(make_pair(-INF,0));
    for(int i=1;i<=n;i++)
        A[i]=gt();
    for(int i=1;i<=n;i++)
        B_pos[B[i]=gt()]=i;
    for(int i=1;i<=n;i++){
        v[A[i]]=i-B_pos[A[i]];
        s.insert(mp(v[A[i]],A[i]));
    }
    for(int i=1;i<=n;i++){
        IT it=s.lower_bound(mp(1-i,0));
        int ans=it-- ->X +i-1;
        ans=min(ans,abs(it->X+i-1));
        s.erase(mp(v[B[i]],B[i]));
        v[B[i]]-=n;
        s.insert(mp(v[B[i]],B[i]));
        printf("%d\n",ans);
    } 
    return 0;
}