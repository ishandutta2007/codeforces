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

const int N = 1e3+5;

struct pir{
	int x,y;
	pir(const int x_=0,const int y_=0){x=x_;y=y_;}
	friend bool operator <(pir a,pir b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
};
map<pir,int>cnt;
int n;
struct point{
	int x,y;
	void read(){
		x=get();y=get();
	}
}a[N],b[N];

int main(){
	n=get();
	fo(i,1,n){
		a[i].read();
	}
	fo(i,1,n)b[i].read();
	fo(i,1,n){
		fo(j,1,n){
			pir u=pir(a[i].x+b[j].x,a[i].y+b[j].y);
			cnt[u]++;
		}
	}
	pir ans;
	for(map<pir,int>::iterator h=cnt.begin();h!=cnt.end();h++)
	if ((*h).second==n){
		ans=(*h).first;
		break;
	}
	cout<<ans.x<<" "<<ans.y<<endl;
	return 0;
}