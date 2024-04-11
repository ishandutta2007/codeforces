#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,type,m,tot;
bool del[MAXN];
set<P> s1,s2;
int main()
{
    scanf("%d",&q);
    memset(del,false,sizeof(del));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            ++tot;
            scanf("%d",&m);
            s1.insert(P(tot,m));
            s2.insert(P(-m,tot));
        }
        else if(type==2)
        {
            P p=*s1.begin();
            printf("%d\n",p.F);
            del[p.F]=true;
            s1.erase(s1.begin());
        }
        else
        {
            P p=*s2.begin();
            while(del[p.S])
            {
                s2.erase(s2.begin());
                p=*s2.begin();
            }
            printf("%d\n",p.S);
            s1.erase(s1.find(make_pair(p.S,-p.F)));
            s2.erase(s2.begin());
        }
    }
    return 0;
}