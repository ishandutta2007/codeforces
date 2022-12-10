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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

ll n,x,m,m2,las;
int q,c;

int main(){
	n=IN(),q=IN();
	while (q--){
		x=IN();
		las=n;
		m=(x-1)/2;
		m2=n/2;
		while (x%2==0){
			x=las+m+1;
			if (las%2==1){
				m-=m/2;
			} else{
				m-=(m+1)/2;
			}
			ll tmp=las+m2;
			if (las%2==1){
				m2-=m2/2;
			} else{
				m2-=(m2+1)/2;
			}
			las=tmp;
		}
		printf("%I64d\n",(x+1)/2);
	}
}