#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int sum[MAXN];
string str;
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
vector<int> v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) v.push_back(i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            sum[i+j]++;
    int s=0;
    for(int i=1;i<=n;i++) s+=sum[i];
    if(m>s)
    {
        puts("-1");
        return 0;
    }
    int cur=n-1,tot=INF;
    while(s>m&&cur>=0)
    {
        for(int i=0;i<cur;i++) sum[v[i]+v[cur]]--;
        int now=v[cur];
        while(s>m&&now<10000)
        {
            s-=sum[now];
            now++;
            s+=sum[now];
        } 
        if(now==10000) {v[cur]=tot; tot-=100000; cur--;} else {v[cur]=now; break;}
    }
    for(auto x:v) printf("%d ",x);
    puts("");
    return 0;
}