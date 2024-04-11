#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n;
mat construct(int n)
{
    if(n==3)
    {
        mat A(3,vec(3));
        A[0][0]=1; A[0][1]=4; A[0][2]=5;
        A[1][0]=7; A[1][1]=6; A[1][2]=9;
        A[2][0]=8; A[2][1]=3; A[2][2]=2;
        return A;
    }
    else
    {
        mat A=construct(n-1);
        mat B(n,vec(n));
        for(int i=0;i<n-1;i++)
            for(int j=1;j<=n-1;j++)
                B[i][j]=A[i][j-1]+2*n-1;
        int tot=0;
        if(n%2==0)
        {
            for(int i=n-1;i>=0;i--) B[n-1][i]=++tot;
            for(int i=n-2;i>=0;i--) B[i][0]=++tot;
        }
        else
        {
            for(int i=0;i<n;i++) B[i][0]=++tot;
            for(int i=1;i<n;i++) B[n-1][i]=++tot;
        }
        return B;
    }
}
int main()
{
    scanf("%d",&n);
    if(n<3) puts("-1");
    else
    {
        mat A=construct(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) printf("%d ",A[i][j]);
            puts("");
        }
    }
    return 0;
}