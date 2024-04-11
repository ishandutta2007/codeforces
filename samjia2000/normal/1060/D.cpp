#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e5+5;

int n;
struct guest{
	int l,r;
}a[N];
struct status{
	int x,v;
	status(const int x_=0,const int v_=0){x=x_;v=v_;}
	friend bool operator <(status a,status b){return a.v!=b.v?a.v>b.v:a.x<b.x;}
};
set<status>l,r;

int main(){
	n=get();
	fo(i,1,n){
		a[i].l=get();
		a[i].r=get();
		l.insert(status(i,a[i].l));
		r.insert(status(i,a[i].r));
	}
	LL ans=0;
	fo(tim,1,n){
		int x=(*l.begin()).x,y=(*r.begin()).x;
		l.erase(l.begin());
		r.erase(r.begin());
		ans=ans+max(a[x].l,a[y].r);
		if (x!=y){
			l.erase(status(y,a[y].l));
			a[x].l=a[y].l;
			l.insert(status(x,a[x].l));
		}
	}
	cout<<ans+n<<endl;
	return 0;
}