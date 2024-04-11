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

const int N=300000+19;

struct node{
	int x,id;
	bool operator < (const node &B) const{
		return x>B.x;
	}
} A[N];
Vi V1,V2;
int vis[N];
int n,s1,s2;

void work(int s1,int s2,bool f){
	memset(vis,0,sizeof(vis));
	For(i,1,n+1){
		vis[i]=vis[i-1]|(1ll*A[i].x*i>=s1);
	}
	For(i,1,n+1){
		int c=(s2/A[i].x)+(s2%A[i].x!=0);
		if (c<=i&&vis[i-c]){
			puts("Yes");
			For(j,1,i-c+1) if (1ll*A[j].x*j>=s1){
				For(k,1,j+1) V1.pb(A[k].id);
				break;
			}
			For(j,0,c) V2.pb(A[i-j].id);
			if (f) swap(V1,V2);
			printf("%d %d\n",V1.size(),V2.size());
			For(i,0,V1.size()) printf("%d ",V1[i]);puts("");
			For(i,0,V2.size()) printf("%d ",V2[i]);puts("");
			exit(0);
		}
	}
}

int main(){
	n=IN(),s1=IN(),s2=IN();
	For(i,1,n+1) A[i]=(node){IN(),i};
	sort(A+1,A+n+1);
	work(s1,s2,0);
	work(s2,s1,1);
	puts("No");
}