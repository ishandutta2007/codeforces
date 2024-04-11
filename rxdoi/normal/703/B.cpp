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

const int N=100000+19;

int n,k;
int c[N],vis[N];
ll sum,res,tmp,num;

int main(){
	n=IN();k=IN();
	For(i,1,n+1) c[i]=IN();
	For(i,1,k+1) vis[IN()]=1;
	For(i,1,n+1){
		sum+=c[i];
		if (vis[i]) tmp+=c[i];
	}
	For(i,1,n+1){
		if (vis[i]){
			res+=1ll*c[i]*(sum-c[i]);
			num+=1ll*c[i]*(tmp-c[i]);
		}
	}
	res-=num/2;
	For(i,1,n) if (!vis[i]&&!vis[i+1]) res+=1ll*c[i]*c[i+1];
	if (!vis[1]&&!vis[n]) res+=1ll*c[1]*c[n];
	cout<<res<<endl;
}