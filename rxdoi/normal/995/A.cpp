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

const int N=200+19;

struct sol{
	int id,x,y;
};vector<sol> res;

int pos1[N],pos2[N],vis[N],A[N],pre[N];
int n,k,tmp,cnt,x,rem;

int main(){
	n=IN(),k=IN();
	For(i,1,n+1) pos1[IN()]=i;
	For(i,1,n+1) pos2[A[i]=IN()]=i;
	For(i,1,n+1) pos2[A[i+n]=IN()]=i+n;
	For(i,1,n+1) pos1[IN()]=i+n;
	For(i,1,k+1) if (!vis[i]&&pos1[i]==pos2[i]){
		vis[i]=1;
		rem++;
		if (pos1[i]<=n){
			res.pb((sol){i,1,pos1[i]});
		} else{
			res.pb((sol){i,4,pos1[i]-n});
		}
		A[pos1[i]]=0;
	}
	if (k==2*n&&rem==0){
		puts("-1");
		return 0;
	}
	For(i,1,2*n+1) if (A[i]==0) x=i;
	while (rem<k){
		if (x==n){
			if (A[2*n]) res.pb((sol){A[2*n],2,n});
			pos2[A[2*n]]=x;
			swap(A[x],A[2*n]);
			x=2*n;
		} lf (x==n+1){
			if (A[1]) res.pb((sol){A[1],3,1});
			pos2[A[1]]=x;
			swap(A[x],A[1]);
			x=1;
		} lf (x<n){
			if (A[x+1]) res.pb((sol){A[x+1],2,x});
			pos2[A[x+1]]=x;
			swap(A[x],A[x+1]);
			x++;
		} else{
			if (A[x-1]) res.pb((sol){A[x-1],3,x-n});
			pos2[A[x-1]]=x;
			swap(A[x],A[x-1]);
			x--;
		}
		For(i,1,k+1) if (!vis[i]&&pos1[i]==pos2[i]){
			vis[i]=1;
			rem++;
			if (pos1[i]<=n){
				res.pb((sol){i,1,pos1[i]});
			} else{
				res.pb((sol){i,4,pos1[i]-n});
			}
			A[pos1[i]]=0;
		}
	}
	printf("%d\n",res.size());
	for (sol S:res) printf("%d %d %d\n",S.id,S.x,S.y);
}