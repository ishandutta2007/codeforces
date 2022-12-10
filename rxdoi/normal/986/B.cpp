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

const int N=1e6+19;

int A[N],C[N];
int n,m,x,y,ans;

int qry(int x){
	int res=0;
	for (;x;x-=x&-x) res^=C[x];
	return res;
}
void add(int x){
	for (;x<=n;x+=x&-x) C[x]^=1;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	for (int i=n;i;i--){
		ans^=qry(A[i]);
		add(A[i]);
	}
	if (n&1){
		puts(ans?"Petr":"Um_nik");
	} else{
		puts(!ans?"Petr":"Um_nik");
	}
}