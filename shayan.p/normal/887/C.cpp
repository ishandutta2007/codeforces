#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct page{ll L,R,U,D;};page p[10];
void read(ll i)
{
ll a,b,c,d;cin>>a>>b>>c>>d;p[i].L=(a==c)?a:-1;p[i].R=(b==d)?b:-1;p[i].U=(a==b)?a:-1;p[i].D=(c==d)?c:-1;
}
bool check(ll a1,ll b1,ll c1,ll d1,ll a2,ll b2,ll c2,ll d2)
{
	if(a1==-1||b1==-1||c1==-1||d1==-1||a2==-1||b2==-1||c2==-1||d2==-1) return 0;
	if((a1==b2&&b1==c2&&c1==d2&&d1==a2)||(a1==d2&&b1==a2&&c1==b2&&d1==c2)) return 1;
	return 0;
}
bool complete(ll i,ll j)
{
	if(p[i].L==-1||p[i].R==-1||p[i].U==-1||p[i].D==-1||p[j].L==-1||p[j].R==-1||p[j].U==-1||p[j].D==-1) return 0;
	return 1;
}
int main()
{
	read(1);read(2);read(3);read(4);read(5);read(6);
	if(complete(1,3)) if(check(p[4].U,p[2].U,p[5].U,p[6].U,p[4].D,p[2].D,p[5].D,p[6].D))cout<<"YES"; else cout<<"NO";
	else if(complete(2,6)) if(check(p[1].U,p[5].R,p[3].D,p[4].L,p[1].D,p[5].L,p[3].U,p[4].R))cout<<"YES"; else cout<<"NO";
	else if(complete(4,5)) if(check(p[1].R,p[2].R,p[3].R,p[6].L,p[1].L,p[2].L,p[3].L,p[6].R))cout<<"YES"; else cout<<"NO";
	else cout<<"NO";
}