#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN];
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
int main()
{
    scanf("%d%d",&T,&n);
    while(T--)
    {
        scanf("%d",&n);
        cin>>str;
        string ans=str;
        int id=1;
        for(int i=1;i<=n-1;i++)
        {
            string x=str.substr(0,i);
            string y=str.substr(i,n-i+1);
            if((n-i)&1) reverse(x.begin(),x.end());
            y+=x;
            if(y<ans)
            {
                ans=y;
                id=i+1;
            }
        }
        cout<<ans<<endl;
        printf("%d\n",id);
    }
    return 0;
}