#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

map<int,int> M;
int n,x,y;
ll ans;

int main(){
	n=IN();
	For(i,0,n){
		x=IN(),y=IN();
		M[x]=max(M[x],y);
	}
	n=IN();
	For(i,0,n){
		x=IN(),y=IN();
		M[x]=max(M[x],y);
	}
	for (auto T:M) ans+=T.se;
	cout<<ans<<endl;
}