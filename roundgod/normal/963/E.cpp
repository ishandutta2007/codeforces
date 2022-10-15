#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int R,b[4],p[4];
bool valid[MAXN][MAXN];
bool vis[MAXN][MAXN];
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
vec gauss_jordan(const mat& A, const vec& b)
{
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];

    for(int i=0;i<n;i++) B[i][n]=b[i];
    for(int i=0;i<n;i++)
    {
        int pivot=i;
        for(int j=i;j<n;j++)
            if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;
        swap(B[i],B[pivot]);
        if(B[i][i]==0) return vec();
        for(int j=i+1;j<=n;j++) B[i][j]=1LL*B[i][j]*pow_mod(B[i][i],MOD-2)%MOD;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                for(int k=i+1;k<=n;k++)
                    dec(B[j][k],1LL*B[j][i]*B[i][k]%MOD);
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;i++)
        x[i]=B[i][n];
    return x;
}
struct coef
{
    vector<int> v;
    friend coef operator + (const coef &x,const coef &y)
    {
        assert(x.v.size()==y.v.size());
        coef ret;
        ret.v.resize(x.v.size());
        for(int i=0;i<(int)x.v.size();i++)
        {
            ret.v[i]=x.v[i];
            add(ret.v[i],y.v[i]);
        }
        return ret;
    }
    friend coef operator - (const coef &x,const coef &y)
    {
        assert(x.v.size()==y.v.size());
        coef ret;
        ret.v.resize(x.v.size());
        for(int i=0;i<(int)x.v.size();i++)
        {
            ret.v[i]=x.v[i];
            dec(ret.v[i],y.v[i]);
        }
        return ret;
    }
    friend coef operator * (const coef &x,int lambda)
    {
        coef ret;
        ret.v.resize(x.v.size());
        for(int i=0;i<(int)x.v.size();i++) ret.v[i]=1LL*x.v[i]*lambda%MOD;
        return ret;
    }
};
coef a[MAXN][MAXN];
mat equations;
vec res;
int main()
{
    scanf("%d",&R);
    int s=0;
    for(int i=0;i<4;i++)
    {
        scanf("%d",&b[i]);
        add(s,b[i]);
    }
    s=pow_mod(s,MOD-2);
    for(int i=0;i<4;i++) p[i]=1LL*b[i]*s%MOD;
    for(int i=0;i<=2*R;i++)
        for(int j=0;j<=2*R;j++)
            a[i][j].v.resize(2*R+2);
    memset(valid,false,sizeof(valid));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=2*R;i++)
        for(int j=0;j<=2*R;j++)
            if((i-R)*(i-R)+(j-R)*(j-R)<=R*R)
                valid[i][j]=true;
    for(int i=0;i<=2*R;i++)
    {
        for(int j=0;j<=2*R;j++)
        {
            if(valid[i][j])
            {
                a[i][j].v[i]=1;
                vis[i][j]=true;
                break;
            }
        }
    }
    for(int j=0;j<=2*R;j++)
    {
        for(int i=0;i<=2*R;i++)
        {
            if(vis[i][j])
            {
                if(valid[i][j+1])
                {
                    coef cur; cur.v.resize(2*R+2);
                    cur=cur+a[i][j];
                    if(i-1>=0) cur=cur-a[i-1][j]*p[0];
                    if(j-1>=0) cur=cur-a[i][j-1]*p[1];
                    if(i+1<=2*R) cur=cur-a[i+1][j]*p[2];
                    dec(cur.v[2*R+1],1);
                    cur=cur*pow_mod(p[3],MOD-2);
                    a[i][j+1]=cur;
                    vis[i][j+1]=true;
                }
                else
                {
                    coef cur; cur.v.resize(2*R+2);
                    cur=cur+a[i][j];
                    if(i-1>=0) cur=cur-a[i-1][j]*p[0];
                    if(j-1>=0) cur=cur-a[i][j-1]*p[1];
                    if(i+1<=2*R) cur=cur-a[i+1][j]*p[2];
                    dec(cur.v[2*R+1],1);
                    cur=cur*pow_mod(p[3],MOD-2);
                    vec tmp=cur.v;
                    int cons=tmp.back(); cons=(MOD-cons)%MOD; tmp.pop_back();
                    equations.push_back(tmp); res.push_back(cons);
                }
            }
        }
    }
    assert(equations.size()==2*R+1);
    vec solu=gauss_jordan(equations,res);
    int ans=0;
    for(int i=0;i<=2*R;i++) add(ans,1LL*solu[i]*a[R][R].v[i]%MOD);
    add(ans,a[R][R].v[2*R+1]);
    printf("%d\n",ans);
    return 0;
}