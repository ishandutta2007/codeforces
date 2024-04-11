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

const int N=1e5+19;

Vi V[N],T;
int n,x,y;

void calc(int x,int fa){
	int tmp=0;
	for (int y:V[x]) if (y!=fa){
		tmp++;
		calc(y,x);
	}
	if (tmp>1){
		puts("No");
		exit(0);
	}
	if (tmp==0){
		T.pb(x);
	}
}

int main(){
	n=IN();
	For(i,1,n){
		x=IN(),y=IN();
		V[x].pb(y);
		V[y].pb(x);
	}
	For(i,1,n+1) if (V[i].size()>=3){
		for (int y:V[i]) calc(y,i);
		if (T.size()&1) T.pb(i);
		puts("Yes");
		printf("%d\n",int(T.size())/2);
		for (int j=0;j<T.size();j+=2) printf("%d %d\n",T[j],T[j+1]);
		exit(0);
	}
	For(i,1,n+1) if (V[i].size()==1) T.pb(i);
	puts("Yes");
	if (T.size()){
		puts("1");
		printf("%d %d\n",T[0],T[1]);
	} else{
		puts("0");
	}
}