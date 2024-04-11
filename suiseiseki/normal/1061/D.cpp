#include <stack>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 100000
#define Mod 1000000007
struct Seg{
	int left,right;
}seg[Maxn+5];
struct Point{
	ll x;
	int id;
	bool l_r;
	friend bool operator <(Point p,Point q){
		if(p.x==q.x){
			return p.l_r<q.l_r;
		}
		return p.x<q.x;
	}
}a[Maxn<<1|5];
stack<ll> st;
int main(){
	int n;
	ll x,y;
	scanf("%d%lld%lld",&n,&x,&y);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&seg[i].left,&seg[i].right);
		a[(i<<1)-1].x=seg[i].left;
		a[(i<<1)-1].id=i;
		a[(i<<1)-1].l_r=0;
		a[i<<1].x=seg[i].right;
		a[i<<1].id=i;
		a[i<<1].l_r=1;
	}
	sort(a+1,a+1+(n<<1));
	ll ans=0;
	ll now,tmp;
	for(int i=1;i<=(n<<1);i++){
		if(a[i].l_r){
			st.push(a[i].x);
		}
		else{
			now=seg[a[i].id].right;
			if(st.empty()){
				ans+=(x+y*(now-a[i].x)%Mod)%Mod;
				ans%=Mod;
			}
			else{
				tmp=st.top();
				if(x+y*(now-a[i].x)>y*(now-tmp)){
					st.pop();
					ans+=y*(now-tmp)%Mod;
					ans%=Mod;
				}
				else{
					ans+=(x+y*(now-a[i].x)%Mod)%Mod;
					ans%=Mod;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}