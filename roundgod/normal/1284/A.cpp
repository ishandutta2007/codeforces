#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
string s[MAXN],t[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=m;i++) cin>>t[i];
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        int a=x%n; if(a==0) a=n;
        int b=x%m; if(b==0) b=m;
        cout<<s[a]<<t[b]<<endl;
    }
    return 0;
}