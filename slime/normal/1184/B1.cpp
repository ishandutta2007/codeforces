#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
ll a[100005],s[100005];
pii b[100005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i].fi=readint(),b[i].se=readint();
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++) s[i]=s[i-1]+b[i].se;
	int pl;
	for(int i=1;i<=n;i++){
		pl=upper_bound(b+1,b+m+1,mp((int)a[i],1<<30))-b-1;
		printf("%lld ",s[pl]);
	}
	printf("\n");
	return 0;
}