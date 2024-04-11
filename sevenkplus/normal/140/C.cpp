#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PI3;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n;set<PII> B;map<int,int> A;vector<PI3> S;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);A[x]++;
    }
    for(map<int,int>::iterator i=A.begin();i!=A.end();i++)
        B.insert(mp(i->se,i->fi));
    while((int)B.size()>=3)
    {
        PII p0=*B.rbegin();B.erase(p0);
        PII p1=*B.rbegin();B.erase(p1);
        PII p2=*B.rbegin();B.erase(p2);
        S.pb(mp(p0.se,mp(p1.se,p2.se)));
        p0.fi--,p1.fi--,p2.fi--;
        if(p0.fi)B.insert(p0);
        if(p1.fi)B.insert(p1);
        if(p2.fi)B.insert(p2);
    }
    printf("%d\n",(int)S.size());
    for(int i=0;i<(int)S.size();i++)
    {
        if(S[i].fi<S[i].se.fi)swap(S[i].fi,S[i].se.fi);
        if(S[i].fi<S[i].se.se)swap(S[i].fi,S[i].se.se);
        if(S[i].se.fi<S[i].se.se)swap(S[i].se.fi,S[i].se.se);
        printf("%d %d %d\n",S[i].fi,S[i].se.fi,S[i].se.se);
    }
    return 0;
}