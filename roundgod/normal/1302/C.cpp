#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S secondN
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int preand[MAXN],sufand[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    preand[0]=sufand[n+1]=(1<<30)-1;
    for(int i=1;i<=n;i++) preand[i]=(preand[i-1]&(~a[i]));
    for(int i=n;i>=1;i--) sufand[i]=(sufand[i+1]&(~a[i]));
    int ans=-1,id=-1;
    for(int i=1;i<=n;i++) 
    {
        if(((preand[i-1]&a[i])&sufand[i+1])>ans)
        {
            ans=((preand[i-1]&a[i])&sufand[i+1]);
            id=i;
        }
    }
    printf("%d",a[id]);
    for(int i=1;i<=n;i++) if(i!=id) printf(" %d",a[i]);
    puts("");
    return 0;
}