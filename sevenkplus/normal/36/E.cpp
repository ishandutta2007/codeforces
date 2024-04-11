#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ins insert
#define N 10010
set<PII> A[N];int n=10000,m,d[N];vector<vector<int> >S;vector<int> T;
void ff(int x)
{
    for(int y,z;!A[x].empty();)
        y=A[x].begin()->fi,z=A[x].begin()->se,
        A[x].erase(mp(y,z)),A[y].erase(mp(x,z)),ff(y),T.pb(z);
}
void gg()
{
    int n=(int)T.size();int p=0;
    for(int i=0;i<n;i++)if(!T[i])p=i+1;
    if(!p)T.pb(0),n++;
    vector<int> U;
    for(int i=0;i<n;p++,i++)
        if(T[p%n])U.pb(T[p%n]);else if(!U.empty())S.pb(U),U.clear();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&m);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),A[x].ins(mp(y,i)),A[y].ins(mp(x,i)),d[x]++,d[y]++;
    vector<int> p;
    for(int i=1;i<=n;i++)if(d[i]&1)p.pb(i);
    for(int i=0,x,y;i<(int)p.size();i+=2)
        x=p[i],y=p[i+1],A[x].ins(mp(y,0)),A[y].ins(mp(x,0));
    for(int i=1;i<=n;i++)T.clear(),ff(i),gg();
    if((int)S.size()==1&&(int)S[0].size()>1)
        S.pb(vector<int>(S[0].begin(),S[0].begin()+1)),
        S.pb(vector<int>(S[0].begin()+1,S[0].end())),
        S.erase(S.begin());
    if((int)S.size()==2)
        for(int i=0;i<2;i++)
        {
            printf("%d\n",(int)S[i].size());
            for(int j=0;j<(int)S[i].size();j++)printf("%d%c",S[i][j],j==(int)S[i].size()-1?'\n':' ');
        }
    else puts("-1");
    return 0;
}