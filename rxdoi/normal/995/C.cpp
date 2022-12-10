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

const int N=1e5+19;
const int top=1500000;

int id[N],x[N],y[N],ans[N];
int n,a,b;

ll cal(int x,int y){
	return 1ll*x*x+1ll*y*y;
}

int main(){
	n=IN();
	For(i,1,n+1) x[i]=IN(),y[i]=IN();
	for (;;){
		a=0,b=0;
		For(i,1,n+1) id[i]=i;
		random_shuffle(id+1,id+n+1);
		For(w,1,n+1){
			int i=id[w];
			if (cal(a+x[i],b+y[i])<cal(a-x[i],b-y[i])){
				a+=x[i];
				b+=y[i];
				ans[i]=1;
			} else{
				a-=x[i];
				b-=y[i];
				ans[i]=-1;
			}
		}
		if (cal(a,b)<=1ll*top*top){
			For(i,1,n+1) printf("%d ",ans[i]);
			puts("");
			return 0;
		}
	}
}