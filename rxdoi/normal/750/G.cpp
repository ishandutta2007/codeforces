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

const int N=50+3;
const int S=51;

ll s,res;

void dp(int a,int b,int x,ll val){
	static ll f[N][N*2][2];
	if (a<0||b<0||x<0||val<0) return;
	if (val&1) return;
	val/=2;
	if (val>(1ll<<max(a,b)+1)-2) return;
	For(i,0,S+1) For(j,0,x+1) For(l,0,2) f[i][j][l]=0;
	f[0][0][0]=1;
	For(i,0,S) For(j,0,x+1) For(l,0,2)
		if (f[i][j][l]){
			For(u,0,2) if (i<a||!u)
				For(v,0,2) if (i<b||!v)
					if ((u+v+l)%2==(val>>i&1)){
						f[i+1][j+u+v][(u+v+l)/2]+=f[i][j][l];
					}
		}
	res+=f[S][x][0];
}
void work(int a,int b){
	ll t,z;
	t=s-((1ll<<a+1)+(1ll<<b+1)-3);
	if (t<0) return;
	z=t/((1ll<<a+1)+(1ll<<b+1)-3)+1;
	t=s-(z-1)*((1ll<<a+1)+(1ll<<b+1)-3);
	for (int i=2;i<=a+b+2;i++){
		dp(max(a-1,0),max(b-1,0),i-(!a?1:1)-(!b?1:2),t+i+1-2*((!a?1ll<<a:2ll<<a-1)+(!b?1ll<<b:3ll<<b-1)));
	}
	/*
	for (int i=1;i<=a+1;i++)
		for (int j=1;j<=b+1;j++){
			dp(max(a-1,0),max(b-1,0),i-(!a?1:1),j-(!b?1:2),t+i+j+1-2*((!a?1ll<<a:2ll<<a-1)+(!b?1ll<<b:3ll<<b-1)));
		}
	*/
}

int main(){
	cin>>s;
	For(a,0,50) For(b,0,50) work(a,b);
	cout<<res<<endl;
}