#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef vector<pair<int,pair<int,int> > > State;
#define fi first
#define se second
#define vx fi
#define vy se.fi
#define vz se.se
#define mp make_pair
#define m3(x,y,z) mp(x,mp(y,z))
#define pb push_back
#define INF 1000000007
int a[3],b[3],c[3],S;
hash_set<int> F;
void ff(State A)
{
    int P=0;
    for(int i=0;i<3;i++)P=((P+A[i].vx)*INF+A[i].vy)*INF+A[i].vz;
    if(F.find(P)!=F.end())return;
    F.insert(P);
    for(int i=0;i<3;i++)S=max(S,A[i].vx);
    for(int i=0;i<3;i++)
    {
        if(A[i].vx==-1)continue;
        //0 move
        if(((A[i].vy>>0)&1)&&A[i].vz==-1)
        {
            for(int j=A[i].vx-b[i];j<=A[i].vx+b[i];j++)
                if(j!=A[0].vx&&j!=A[1].vx&&j!=A[2].vx)
                {
                    State B=A;
                    B[i].vy^=(1<<0),
                    B[i].vx=j,ff(B);
                }
        }
        //1 grab
        if((A[i].vy>>1)&1)
        {
            for(int j=0;j<3;j++)
                if(abs(A[i].vx-A[j].vx)==1)
                {
                    State B=A;
                    B[j].vx=-1,B[i].vz=j,
                    B[i].vy^=(1<<1),ff(B);
                }
        }
        //2 throw
        if(((A[i].vy>>2)&1)&&A[i].vz!=-1)
        {
            int k=A[i].vz;
            for(int j=A[i].vx+1;j<=A[i].vx+c[i];j++)
                if(j!=A[0].vx&&j!=A[1].vx&&j!=A[2].vx)
                {
                    State B=A;
                    B[i].vy^=(1<<2),B[i].vz=-1,
                    B[k].vx=j,ff(B);
                }
        }
    }
}
int main()
{
    for(int i=0;i<3;i++)scanf("%d%d%d",a+i,b+i,c+i),S=max(S,a[i]+=100);
    State A;A.pb(m3(a[0],7,-1)),A.pb(m3(a[1],7,-1)),A.pb(m3(a[2],7,-1));
    ff(A);
    printf("%d\n",S-100);
    return 0;
}