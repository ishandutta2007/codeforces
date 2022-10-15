#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,x,y;
string ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d%d",&x,&y);
    for(int i=1;i<=k;i++) scanf("%d%d",&x,&y);
    for(int i=1;i<=n-1;i++) ans+='U';
    for(int i=1;i<=m-1;i++) ans+='L';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-1;j++)
            if(i&1) ans+='R'; else ans+='L';
        if(i!=n) ans+='D';
    }
    printf("%d\n",(int)ans.size());
    cout<<ans<<endl;
    return 0;
}