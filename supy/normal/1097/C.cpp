#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,cnt1[N],cnt2[N],res;char s[N];
bool ck1(int n){
	int v=0;
	rep(i,1,n){
		v+=s[i]=='('?1:-1;if(v<0)return 0;
	}
	return 1;
}
bool ck2(int n){
	int v=0;
	per(i,n,1){
		v+=s[i]==')'?1:-1;if(v<0)return 0;
	}
	return 1;
}
int main() {
	read(n);
	rep(t,1,n){
		scanf("%s",s+1);int l=strlen(s+1);
		int tot=0;rep(i,1,l)tot+=s[i]=='('?1:-1;
		if(tot>=0){if(ck1(l))cnt1[tot]++;}//0
		else{if(ck2(l))cnt2[-tot]++;}
	}
	rep(i,1,N-1)res+=min(cnt1[i],cnt2[i]);res+=cnt1[0]/2;
	cout<<res;
	return 0;
}