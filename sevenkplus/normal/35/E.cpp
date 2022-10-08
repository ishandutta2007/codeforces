#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100010
struct R
{
    int x,y,z;
    R(){}
    R(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
    void get(){scanf("%d%d%d",&z,&x,&y);}
    bool operator < (const R&a) const {return z>a.z||z==a.z&&x<a.x||z==a.z&&x==a.x&&y<a.y;}
    bool operator == (const R&a) const {return x==a.x&&y==a.y&&z==a.z;}
}a[N];
map<int,vector<int> > A;vector<PII> S;set<R> B;
int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i].get();
    sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a;
    for(int i=1;i<=n;i++)A[a[i].x].pb(i),A[a[i].y].pb(-i);
    int ma=0;
    for(map<int,vector<int> >::iterator i=A.begin();i!=A.end();i++)
    {
        for(vector<int>::iterator j=i->se.begin();j!=i->se.end();j++)
            if(*j>0)B.insert(a[*j]);else B.erase(a[-*j]);
        int ma2=0;if(!B.empty())ma2=B.begin()->z;
        if(ma!=ma2)S.pb(mp(i->fi,ma)),S.pb(mp(i->fi,ma2));ma=ma2;
    }
    printf("%d\n",(int)S.size());
    for(int i=0;i<(int)S.size();i++)printf("%d %d\n",S[i].fi,S[i].se);
    return 0;
}