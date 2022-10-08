#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int a[200010],n,S,T;vector<PII> A;set<PII> B;
int main()
{
    scanf("%d%d",&n,&S);
    for(int i=1;i<=n;i++)scanf("%d",a+i),B.insert(mp(a[i],i));
    if(S&1){puts("No");return 0;}
    for(int i=n;i>=1;i--)
    {
        PII x=*B.rbegin();B.erase(x);
        if(x.fi>=i||x.fi<0){puts("No");return 0;}
        vector<PII> C;
        for(int j=0;j<x.fi;j++)
        {
            PII y=*B.rbegin();B.erase(y),
            a[y.se]--,y.fi--,C.pb(y),A.pb(mp(x.se,y.se));
        }
        for(int j=0;j<(int)C.size();j++)B.insert(C[j]);
    }
    puts("Yes");
    printf("%d\n",(int)A.size());
    for(int i=0;i<(int)A.size();i++)
        printf("%d %d\n",A[i].fi,A[i].se);
    return 0;
}