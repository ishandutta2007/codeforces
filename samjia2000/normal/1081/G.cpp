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

int n,k,q;
map<int,int>cnt;
LL ans;
LL js[N],inv[N];
int mo;

void build(int l,int r,int h){
	if (l==r||h<=1){cnt[r-l+1]++;return;}
	int mid=(l+r)/2;
	build(l,mid,h-1);
	build(mid+1,r,h-1);
}

LL calc(int la,int lb){
	LL ret=inv[2]*la%mo*lb%mo;
	fo(i,2,la+lb){
		int l=1,r=la;
		l=max(l,i-lb);
		r=min(r,i-1);
		ret=(ret+mo-1ll*(r-l+1)*inv[i]%mo)%mo;
	}
	return ret;
}

int main(){
	n=get();k=get();mo=q=get();
	build(1,n,k);
	inv[0]=inv[1]=1;
	fo(i,2,1e5)inv[i]=1ll*(q-q/i)*inv[q%i]%q;
	for(map<int,int>::iterator h=cnt.begin();h!=cnt.end();h++){
		int s=(*h).first,c=(*h).second;
		ans=(ans+1ll*s*(s-1)*inv[4]%q*c%q)%q;
		map<int,int>::iterator p=h;
		ans=(ans+inv[2]*c*(c-1)%mo*calc(s,s)%mo)%mo;
		p++;
		for(;p!=cnt.end();p++)ans=(ans+1ll*c*(*p).second%mo*calc(s,(*p).first))%mo;
	}
	cout<<ans<<endl;
	return 0;
}