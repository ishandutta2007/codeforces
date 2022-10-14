#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 1000000006
#define mod 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

//?????????
struct MATRIX
{
    LL row,col;
    LL data[4][4];

    MATRIX(int n,int m)
    {
        row=n;
        col=m;
        RPT(i,0,n)
            RPT(j,0,n)
                data[i][j]=0;
    }

    MATRIX(const MATRIX &m)
    {
        *this=m; 
    }

    ~MATRIX()
    {
    }

    void input()
    {
        RPT(i,0,row)
            RPT(j,0,col)
                scanf("%d",&data[i][j]);
    }

    void output()
    {
        if (!islegal())
        {
            cout<<"illegal matrix!"<<endl;
            return;
        }
        RPT(i,0,row)
        {
            RPT(j,0,col)
                printf("%d ",data[i][j]);
            printf("\n");
        }
    }

    bool islegal()
    {
        if (col<=0 || row<=0)
            return false;
        return true;
    }

    MATRIX operator - ()
    {
        if (!this->islegal())
        {
            MATRIX fault(-1,-1);
            return fault;
        }
        MATRIX ans(row,col);
        RPT(i,0,row)
            RPT(j,0,col)
                ans.data[i][j]=((-this->data[i][j])%MOD+MOD)%MOD;
        return ans;
    }

    MATRIX operator + (MATRIX m)
    {
        if (this->col!=m.col || this->row!=m.col || !this->islegal() || !m.islegal())
        {
            MATRIX fault(-1,-1);
            return fault;
        }
        MATRIX ans(*this);
        RPT(i,0,row)
            RPT(j,0,col)
                ans.data[i][j]=(ans.data[i][j]+m.data[i][j])%MOD;
        return ans;
    }

    MATRIX operator - (MATRIX m)
    {
        if (this->col!=m.col || this->row!=m.col || !this->islegal() || !m.islegal())
        {
            MATRIX fault(-1,-1);
            return fault;
        }
        MATRIX ans(*this);
        RPT(i,0,row)
            RPT(j,0,col)
                ans.data[i][j]=((ans.data[i][j]-m.data[i][j])%MOD+MOD)%MOD;
        return ans;
    }

    MATRIX operator * (MATRIX m)
    {
        if (this->col!=m.row || !this->islegal() || !m.islegal())
        {
            MATRIX fault(-1,-1);
            return fault;
        }
        MATRIX ans(this->row,m.col);
        RPT(i,0,ans.row)
            RPT(j,0,ans.col)
                RPT(k,0,this->col)
                    ans.data[i][j]=(ans.data[i][j]+this->data[i][k]*m.data[k][j])%MOD;
        return ans;
    }
};
LL fastpow(LL x,LL n)
{
    LL ans=1;
    while (n)
    {
        if (n&1)
            ans=ans*x%mod;
        x=x*x%mod;
        n/=2;
    }
    return ans;
}

LL inv(LL x)
{
	return fastpow(x,mod-2);
}

LL n,f1,f2,f3,c;
MATRIX m(1,3),a(3,3);
MATRIX s(3,3);
void init()
{
	cin>>n>>f1>>f2>>f3>>c;
	if (n==1)
	{
		cout<<f1%mod;
		exit(0);
	}
	if (n==2)
	{
		cout<<f2%mod;
		exit(0);
	}
	if (n==3)
	{
		cout<<f3%mod;
		exit(0);
	}
	f1=f1*fastpow(c,1)%mod;
	f2=f2*fastpow(c,2)%mod;
	f3=f3*fastpow(c,3)%mod;
	a.data[1][0]=1;
	a.data[2][1]=1;
	a.data[0][2]=1;
	a.data[1][2]=1;
	a.data[2][2]=1;
	s.data[0][0]=1;
	s.data[1][1]=1;
	s.data[2][2]=1;
} 


int main()
{
	init();
	LL nn=n;
	n=n-3;
	while (n)
	{
		if (n&1)
			s=s*a;
		a=a*a;
		n=n/2;
	}
	LL ans=1;
	ans=ans*fastpow(f1,s.data[0][2])%mod;
	ans=ans*fastpow(f2,s.data[1][2])%mod;
	ans=ans*fastpow(f3,s.data[2][2])%mod;
	ans=ans*inv(fastpow(c,nn))%mod;
	cout<<ans;
    return ~~(0^_^0);
}