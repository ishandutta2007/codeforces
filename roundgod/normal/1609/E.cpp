#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<int> a,b,c;
int n,q;
string str;
struct segtree
{
    int a[4*MAXN],b[4*MAXN],c[4*MAXN],ab[4*MAXN],bc[4*MAXN],abc[4*MAXN];
    void pushup(int k)
    {
        int abpc=min(ab[k*2],c[k*2+1]);// ab and c -> abc
        int apbc=min(a[k*2],bc[k*2+1]);// a and bc -> abc
        int abpbc=min(ab[k*2]-abpc,bc[k*2+1]-apbc); //ab and bc -> abc + b(left) (no a in left, no c in right)
        int apb=min(a[k*2]-apbc,b[k*2+1]);//a and b -> ab
        int bpc=min(b[k*2]+abpbc,c[k*2+1]-abpc);//b and c -> bc
        abc[k]=abc[k*2]+abc[k*2+1]+abpc+apbc+abpbc;
        ab[k]=ab[k*2]+ab[k*2+1]-abpc-abpbc+apb;
        bc[k]=bc[k*2]+bc[k*2+1]-apbc-abpbc+bpc;
        a[k]=a[k*2]+a[k*2+1]-apb-apbc;
        b[k]=b[k*2]+b[k*2+1]-apb+abpbc-bpc;
        c[k]=c[k*2]+c[k*2+1]-abpc-bpc;
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            a[k]=b[k]=c[k]=ab[k]=bc[k]=abc[k]=0;
            if(str[l]=='a') a[k]=1; else if(str[l]=='b') b[k]=1; else c[k]=1;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p,int type)
    {
        if(l==r)
        {
            a[k]=b[k]=c[k]=0;
            if(type==0) a[k]=1; else if(type==1) b[k]=1; else c[k]=1;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,type); else update(k*2+1,mid+1,r,p,type);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    seg.build(1,0,n-1);
    for(int i=0;i<q;i++)
    {
        int x;
        string s;
        scanf("%d",&x); x--;
        cin>>s;
        seg.update(1,0,n-1,x,s[0]-'a');
        printf("%d\n",seg.abc[1]);
    }
    return 0;
}