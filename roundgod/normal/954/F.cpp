#include<bits/stdc++.h>
#define MAXN 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
set<ll> s;
map<ll,int> mp;
ll n,m;
ll a[MAXN],l[MAXN],r[MAXN],len[MAXN],save[MAXN];
ll blocked[3][MAXN];
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(ll i=0;i<A.size();i++)
        for(ll k=0;k<B.size();k++)
            for(ll j=0;j<B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}
mat _pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(ll i=0;i<A.size();i++)
        B[i][i]=1LL;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int main()
{
	mat A1(3,vec(3)),A2(3,vec(3)),A3(3,vec(3)),A4(3,vec(3)),A5(3,vec(3)),A6(3,vec(3)),A7(3,vec(3)),A8(3,vec(3));
	A1[0][0]=A1[0][1]=A1[1][0]=A1[1][1]=A1[1][2]=A1[2][2]=A1[2][1]=1;A1[0][2]=A1[2][0]=0;
	A2=A3=A4=A5=A6=A7=A8=A1;
	for(ll i=0;i<3;i++)
		A2[0][i]=A4[0][i]=A6[0][i]=A8[0][i]=0;
	for(ll i=0;i<3;i++)
		A3[1][i]=A4[1][i]=A7[1][i]=A8[1][i]=0;
	for(ll i=0;i<3;i++)
		A5[2][i]=A6[2][i]=A7[2][i]=A8[2][i]=0;
	scanf("%I64d%I64d",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&a[i],&l[i],&r[i]);
		r[i]++;
		s.insert(l[i]);
		s.insert(r[i]);
	}
	ll t=0;
	for(auto it=s.begin();it!=s.end();it++)
	{
		save[++t]=*it;
		mp[save[t]]=t;
	}
	for(ll i=1;i<=n;i++)
	{
		l[i]=mp[l[i]];
		r[i]=mp[r[i]];
	}
	//for(ll i=1;i<=n;i++)
		//printf("%I64d %I64d\n",l[i],r[i]);
	memset(blocked,0,sizeof(blocked));
	for(ll i=1;i<=n;i++)
	{
		blocked[a[i]-1][l[i]]++;
		blocked[a[i]-1][r[i]]--;
	}
	for(ll i=0;i<3;i++)
	{
		for(ll j=1;j<=t;j++)
		{
			blocked[i][j]+=blocked[i][j-1];
			//printf("%I64d ",blocked[i][j]);
		}
		//puts("");
	}
	mat x(3,vec(1)); x[0][0]=0;x[1][0]=1;x[2][0]=0;
	x=mul(_pow(A1,save[1]-2),x);
	//puts("");
	for(ll i=1;i<t;i++)
	{
		ll num=0;
		if(blocked[2][i]) num+=4;
		if(blocked[1][i]) num+=2;
		if(blocked[0][i]) num+=1;
		num++;
		//printf("%I64d\n",num);
		ll len=(save[i+1]-save[i])%(MOD-1);
		if(num==1) x=mul(_pow(A1,len),x);
		if(num==2) x=mul(_pow(A2,len),x);
		if(num==3) x=mul(_pow(A3,len),x);
		if(num==4) x=mul(_pow(A4,len),x);
		if(num==5) x=mul(_pow(A5,len),x);
		if(num==6) x=mul(_pow(A6,len),x);
		if(num==7) x=mul(_pow(A7,len),x);
		if(num==8) x=mul(_pow(A8,len),x);
		//puts("");
	}
	x=mul(_pow(A1,m-save[t]+1),x);
	printf("%I64d\n",x[1][0]);
	return 0;
}