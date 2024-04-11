#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
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
    scanf("%d",&n);
    int ans=pow_mod(2,n)-1;
    vector<int> v;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]%2==0) v.push_back(a[i]);
    }
    while(v.size())
    {
        vector<int> even,odd;
        odd.clear(); even.clear();
        for(auto x:v) if(x%4==2) odd.push_back(x/2); else even.push_back(x/2);
        //at least one odd
        if(odd.size()) dec(ans,1LL*pow_mod(2,(int)odd.size()-1)*pow_mod(2,(int)even.size())%MOD);
        v=even;
    }
    printf("%d\n",ans);
    return 0; 
}