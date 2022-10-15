#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef vector<double> vec;
typedef vector<vec> mat;
typedef long long ll;
int n,m,k;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
        for(int k=0;k<B.size();k++)
            for(int j=0;j<B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
    return C;
}
mat _pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
mat get_inv(mat A)
{
    mat B(n,vec(n));
    for(int i=0;i<n;i++) B[i][i]=1.0;
    for (int k = 0; k < n; ++k) 
    {
            int pv = k;
            for (int i = k + 1; i < n; ++i) {
                if (fabsl(A[i][k]) > fabsl(A[pv][k])) {
                    pv = i;
                }
            }
 
            for (int j = 0; j < n; ++j) {
                swap(A[k][j], A[pv][j]);
                swap(B[k][j], B[pv][j]);
            }
 
            double e = A[k][k];
            for (int j = 0; j < n; ++j) {
                A[k][j] /= e;
                B[k][j] /= e;
            }
            for (int i = k + 1; i < n; ++i) {
                e = A[i][k];
                for (int j = 0; j < n; ++j) {
                    A[i][j] -= A[k][j] * e;
                    B[i][j] -= B[k][j] * e;
                }
            }
        }
 
        for (int k = n - 1; k >= 0; --k) {
            for (int i = 0; i < k; ++i) {
                double e = A[i][k];
                for (int j = 0; j < n; ++j) {
                    A[i][j] -= A[k][j] * e;
                    B[i][j] -= B[k][j] * e;
                }
            }            
        }
    return B;
}
int type[MAXN];
vector<int> G[MAXN];
vector<int> holes;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int cnt=0;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&type[i]);
        if(type[i])
        {
            cnt++;
            holes.push_back(i);
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v); u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    mat A(n,vec(n)),B(n,vec(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) A[i][j]=0.0;
        int sz=(int)G[i].size();
        for(auto to:G[i]) if(type[to]) A[i][to]+=1.0/sz;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) B[i][j]=0.0;
        int sz=(int)G[i].size();
        for(auto to:G[i]) if(!type[to]) B[i][to]+=1.0/sz;
        for(int j=0;j<n;j++) if(i==j) B[i][j]=1.0-B[i][j]; else B[i][j]=-B[i][j];
    }
    
    A=mul(get_inv(B),A);
    mat X(cnt,vec(cnt));
    for(int i=0;i<(int)holes.size();i++)
        for(int j=0;j<(int)holes.size();j++)
            X[i][j]=A[holes[i]][holes[j]];
    X=_pow(X,k-2);
    mat y(1,vec(cnt));
    for(int i=0;i<(int)holes.size();i++) y[0][i]=A[0][holes[i]];
    y=mul(y,X);
    printf("%.10f\n",y[0][cnt-1]);
    return 0;
}