#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
typedef vector<string> Vs;

const int N=2000000+19;
const int p1=998244353;
const int p2=1e9+7;

map<pii,int> M;
int vis[N],chk[N],f[N],g[N],pw1[N],pw2[N],n,k,m,Time;
string s,t;
char str[N];

int main(){
	pw1[0]=1;
	For(i,1,N) pw1[i]=29ll*pw1[i-1]%p1;
	pw2[0]=1;
	For(i,1,N) pw2[i]=5ll*pw2[i-1]%p2;
	n=IN(),k=IN();
	cin>>s;
	s=s+s;
	m=IN();
	For(a,1,m+1){
		scanf("%s",str);
		t=string(str);
		int res1=0,res2=0;
		For(i,0,t.length()){
			res1=(res1*29ll+t[i]-'a')%p1;
			res2=(res2*5ll+t[i]-'a')%p2;
		}
		M[mp(res1,res2)]=a;
	}
	For(i,0,s.length()){
		f[i+1]=(f[i]*29ll+s[i]-'a')%p1;
		g[i+1]=(g[i]*5ll+s[i]-'a')%p2;
	}
	For(i,0,n*k){
		int res1=(f[i+k]-1ll*f[i]*pw1[k]%p1+p1)%p1;
		int res2=(g[i+k]-1ll*g[i]*pw2[k]%p2+p2)%p2;
		vis[i]=M[mp(res1,res2)];
	}
	For(i,0,k){
		int b=1;
		chk[0]=++Time;
		for (int j=i;j<n*k;j+=k){
			if (chk[vis[j]]==Time) b=0;
			chk[vis[j]]=Time;
		}
		if (!b) continue;
		puts("YES");
		for (int j=i;j<n*k;j+=k) printf("%d ",vis[j]);
		return 0;
	}
	puts("NO");
}