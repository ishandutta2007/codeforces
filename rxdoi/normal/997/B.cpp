#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=100;
const int M=100000;

int f[M];
int n,tmp;
set<ll> S;

int main(){
	For(i,0,N) For(j,0,N) f[4*i+9*j]=1;
	For(i,0,M) if (f[i]) if (i-49<0||!f[i-49]) tmp++;
	n=IN();
	For(d,max(n-200,0),n+1){
		For(b,0,9){
			For(c,0,49)
				if (b+c+d<=n) S.insert(4ll*b+9ll*c+49ll*d);
		}
	}
	cout<<int(S.size())+1ll*max(n-200,0)*tmp<<endl;
}