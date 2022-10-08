#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1000000000000000000LL;
int n;vector<int> p,q,r,s;ll S=INF;
bool pr(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
void ccp()
{
    for(int i=2;p.size()<9;i++)
        if(pr(i))p.push_back(i);
    s.resize(p.size());
    for(int i=0;i<p.size();i++)
    {
        ll S=1;
        while(S<=INF/p[i])S*=p[i],s[i]++;
    }
}
void gg()
{
    ll T=1;
    for(int i=0;i<p.size();i++)
        for(int j=1;j<r[i];j++)
            if(T>INF/p[i])return;else T*=p[i];
    S=min(S,T);
}
void ff(int b)
{
    if(b==(int)q.size()){gg();return;}
    for(int i=0;i<9;i++)
        if(r[i]*q[b]<=s[i])r[i]*=q[b],ff(b+1),r[i]/=q[b];
}
int main()
{
    ccp();
    scanf("%d",&n);
    r.resize(p.size(),1);
    for(int i=2;n!=1;i++)
        while(n%i==0)q.push_back(i),n/=i;
    ff(0);
    printf("%I64d\n",S);
    return 0;
}