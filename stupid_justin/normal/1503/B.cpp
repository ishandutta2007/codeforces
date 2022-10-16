#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(int &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,x,cnt1,cnt2,p1,p2,p3,p4,q1,q2;
int main()
{
	cin>>n;
	cnt2=n*n/2;
	cnt1=n*n-cnt2;
	p1=p2=p3=1,p4=2;
	rep(i,1,n*n)
	{
		rd(x);
		if ((x==1||x==3)&&q2<cnt2) q2++,cout<<"2 "<<p3<<' '<<p4<<endl,p4+=2,p4>n&&(p3++,p4=p3&1,p4++);
		else if ((x==2||x==3)&&q1<cnt1) q1++,cout<<"1 "<<p1<<' '<<p2<<endl,p2+=2,p2>n&&(p1++,p2=(p1&1)^1,p2++);
		else if (q1==cnt1) q2++,cout<<"3 "<<p3<<' '<<p4<<endl,p4+=2,p4>n&&(p3++,p4=p3&1,p4++);
		else q1++,cout<<"3 "<<p1<<' '<<p2<<endl,p2+=2,p2>n&&(p1++,p2=(p1&1)^1,p2++);
	}
	return 0;
}