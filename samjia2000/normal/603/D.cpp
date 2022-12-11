#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long double db;
typedef long long LL;

const int N = 2005;
const db eps = 1e-12;

int n;
struct point{
	LL x,y,v;
}a[N];
map<pair<LL,LL>,int>mp;

LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

pair<LL,LL>work(LL x,LL y){
	if (x<0)x=-x,y=-y;
	LL g=gcd(x,y);
	x/=g,y/=g;
	return make_pair(x,y);
}

int main(){
	//freopen("x.in","r",stdin);
	//freopen("x.out","w",stdout);
	cin>>n;
	int cnt=0;
	fo(i,1,n){
		LL A,B,C;
		cin>>A>>B>>C;
		a[i].x=A*C;
		a[i].y=B*C;
		a[i].v=A*A+B*B;
	}
	LL ans=0;
	fo(i,1,n){
		mp.clear();
		fo(j,i+1,n){
			LL u=a[i].x*a[j].v-a[j].x*a[i].v;
			LL v=a[i].y*a[j].v-a[j].y*a[i].v;
			if (u==0&&v==0)ans=ans+n-1-i;
			else ans+=(mp[work(u,v)]++);
		}
	}
	cout<<ans<<endl;
	return 0;
}