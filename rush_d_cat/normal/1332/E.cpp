#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
LL n,m,L,R;
const LL MOD=998244353;
LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}

struct Matrix
{
    LL a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%MOD;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
} M;
/*
f[i][0] = even * f[i-1][0] + odd * f[i-1][1]
f[i][1] = odd * f[i-1][0] + even * f[i-1][1]
*/
int main() {
	cin>>n>>m>>L>>R;
	LL t=n*m;
	if(t%2==1){
		cout<<mpow(R-L+1,t)<<endl;
	}else{
		LL odd=0,even=0;
		even+=R/2; odd+=(R+1)/2;
		even-=(L-1)/2; odd-=(L-1+1)/2;
		M.a[0][0]=even,M.a[0][1]=odd;
		M.a[1][0]=odd,M.a[1][1]=even;
		M=M^t;
		printf("%lld\n", M.a[0][0]);
	}
}