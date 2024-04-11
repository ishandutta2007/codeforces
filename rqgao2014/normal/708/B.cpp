#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

ll a,b,c,d;
int n,x,y;
vi ans;
inline int get(ll x){
	for(int i=1;;i++){
		ll t=(ll)i*(i-1)/2;
		if(t>x) return -1;
		if(t==x) return i;
	}
}
inline bool check(int n,int x,int y){
	ans.clear();
	if(n==-1||x==-1||y==-1||x+y!=n) return 0;
	for(int i=1;i<=n;i++)
		if(y<=b) ans.pb(0),b-=y; else ans.pb(1),y--; 
	for(int i=0;i<n;i++)
		putchar(ans[i]+'0');
	puts("");
	return 1;
}

int main(){
	cin>>a>>b>>c>>d;
	n=get((ll)a+b+c+d);
	x=get(a);y=get(d);
	if(x==1){
		if(y==1){
			if(check(n,0,1)) return 0;
			if(check(n,1,0)) return 0;
			if(check(n,1,1)) return 0;
		}
		else{
			if(check(n,0,y)) return 0;
			if(check(n,1,y)) return 0;	
		}
		puts("Impossible");
	}
	else if(y==1){
		if(check(n,x,0)) return 0;
		if(check(n,x,1)) return 0;
		puts("Impossible");
	}
	else if(!check(n,x,y)) puts("Impossible");
	return 0;
}