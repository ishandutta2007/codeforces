#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 200005
#define MAXA 1000005
using namespace std;
typedef long long ll;
inline int scan()
{
	int n = 0, x = getchar(), s =1;

	for (;x<'0'||x>'9';x=getchar()) if(x=='-') s=-1;
	for (;x>='0'&&x<='9';x=getchar()) n = (n<<3) + (n<<1) + x-'0';
	return n;
}
struct query
{
    int l,r,ll,rl,id;
}save[MAXM];
ll cnt[MAXA],out[MAXN];
int a[MAXN];
int n,m;
ll ans,cl,cr,block;
bool cmp(query x,query y)
{
    if(x.ll!=y.ll) return x.ll<y.ll;
    return x.r<y.r^(x.ll/block%2);
}
void add(ll pos)
{
     ans+=(2*cnt[a[pos]]+1)*a[pos];
        cnt[a[pos]]++;
    return;
}
void del(ll pos)
{
    cnt[a[pos]]--;
    ans-=(2*cnt[a[pos]]+1)*a[pos];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    n=scan();
    m=scan();
    block=(ll)3*sqrt(n)/2;
    for(int i=1;i<=n;i++)
        a[i]=scan();
    for(int i=0;i<m;i++)
    {
        save[i].id=i;
        save[i].l=scan();
        save[i].r=scan();
        save[i].ll=save[i].l/block;
        save[i].rl=save[i].r/block;
    }
    sort(save,save+m,cmp);
    memset(cnt,0,sizeof(cnt));
    ans=0;
    for(int i=save[0].l;i<=save[0].r;i++)
    {
        ans+=(2*cnt[a[i]]+1)*a[i];
        cnt[a[i]]++;

    }
    out[save[0].id]=ans;
    cl=save[0].l,cr=save[0].r;
    for(int i=1;i<m;i++)
    {
        while(cl<save[i].l)
        {
            del(cl);
            cl++;
        }
        while(cl>save[i].l)
        {
            cl--;
            add(cl);
        }
        while(cr>save[i].r)
        {
            del(cr);
            cr--;
        }
        while(cr<save[i].r)
        {
            cr++;
            add(cr);
        }
        out[save[i].id]=ans;
    }
    for(int i=0;i<m;i++)
        printf("%I64d\n",out[i]);
    return 0;
}