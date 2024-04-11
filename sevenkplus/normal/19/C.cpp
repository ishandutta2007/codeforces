#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define N 131073
#define P 1000000007
typedef map<int,vector<int> > M;
struct PII{int l,r;PII(){}PII(int _l,int _r):l(_l),r(_r){}};
vector<PII>A;
int a[N],n,c[N],d[N];M p;
inline int hh(int l,int r){return c[r]-c[l-1]*d[r-l+1];}
inline bool can(int l,int r){return r+r-l-1<=n&&hh(l,r-1)==hh(r,r+r-l-1);}
inline bool cmp(const PII&a,const PII&b){if(a.r-a.l!=b.r-b.l)return a.r-a.l<b.r-b.l;else return a.l<b.l;}
int main()
{
    scanf("%d",&n);d[0]=1;for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]=x,p[x].push_back(i),c[i]=c[i-1]*P+x,d[i]=d[i-1]*P;
    for(M::iterator I=p.begin();I!=p.end();I++)
        for(int i=0;i<I->second.size();i++)
            for(int j=i+1;j<I->second.size();j++)
                if(can(I->second[i],I->second[j]))A.push_back(PII(I->second[i],I->second[j]));
    sort(A.begin(),A.end(),cmp);int C=0;
    for(vector<PII>::iterator I=A.begin();I!=A.end();I++)if(I->l>C)C=I->r-1;
    printf("%d\n",n-C);for(int i=C+1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}