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

const int N=2000+19;

int A[N],f[N][3],c[N][3];
int n,ans;

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		c[i][1]=c[i-1][1]+(A[i]==1);
		c[i][2]=c[i-1][2]+(A[i]==2);
	}
	For(i,1,n+1){
		memset(f,0,sizeof(f));
		f[i][A[i]]=1;
		For(j,i+1,n+1){
			if (A[j]==1){
				f[j][1]=max(f[j-1][1],f[j-1][2])+1;
				f[j][2]=f[j-1][2];
			} else{
				f[j][1]=f[j-1][1];
				f[j][2]=f[j-1][2]+1;
			}
		}
		For(j,i,n+1){
			ans=max(ans,max(f[j][1],f[j][2])+c[i-1][1]+c[n][2]-c[j][2]);
		}
	}
	For(i,0,n+1) ans=max(ans,c[i][1]+c[n][2]-c[i][2]);
	printf("%d\n",ans);
}