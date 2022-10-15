#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p;
deque<int> a,b;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x); x%=p;
        a.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x); x%=p;
        b.push_back(x);
    }
    int shift=0;
    while(a.size()&&b.size())
    {
        if(a[0]&&b[0]) break;
        else if(!a[0]) a.pop_front();
        else b.pop_front();
        shift++;
    }
    printf("%d\n",shift);
    return 0;
}