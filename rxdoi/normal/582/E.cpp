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

const int N=500+19;
const int p=1e9+7;

char s[N];
int w[N],v[N],f[N][1<<16];
int A[1<<16],B[1<<16],C[1<<16];
int n,m,res,num;

void U(int &x,int y) {x=(x+y)%p;}
void FWT_O(int *A,int f){
	for (int i=1;i<1<<16;i<<=1)
		for (int j=0;j<1<<16;j+=i<<1)
			For(k,j,j+i){
				U(A[k+i],!f?A[k]:p-A[k]);
			}
}
void FWT_A(int *A,int f){
	for (int i=1;i<1<<16;i<<=1)
		for (int j=0;j<1<<16;j+=i<<1)
			For(k,j,j+i){
				U(A[k],!f?A[k+i]:p-A[k+i]);
			}
}
int Work(int l,int r){
	int x=++num;
	if (l==r){
		For(i,0,4)
			if (s[l]=='?'||s[l]=='A'+i){
				int s=0;
				For(t,0,16) s|=(t>>i&1)<<t;
				f[x][s]++;
			}
		For(i,0,4)
			if (s[l]=='?'||s[l]=='a'+i){
				int s=0;
				For(t,0,16) s|=(t>>i&1^1)<<t;
				f[x][s]++;
			}
	} else{
		int tmp=0,mid,lsn,rsn;
		For(i,l,r+1){
			if (s[i]=='(') tmp++;
			if (s[i]==')') if (--tmp==0) {mid=i+1;break;}
		}
		lsn=Work(l+1,mid-2);
		rsn=Work(mid+2,r-1);
		if (s[mid]=='?'||s[mid]=='|'){
			memcpy(A,f[lsn],sizeof(f[lsn]));
			memcpy(B,f[rsn],sizeof(f[rsn]));
			FWT_O(A,0);
			FWT_O(B,0);
			For(t,0,1<<16) C[t]=1ll*A[t]*B[t]%p;
			FWT_O(C,1);
			For(t,0,1<<16) U(f[x][t],C[t]);
		}
		if (s[mid]=='?'||s[mid]=='&'){
			memcpy(A,f[lsn],sizeof(f[lsn]));
			memcpy(B,f[rsn],sizeof(f[rsn]));
			FWT_A(A,0);
			FWT_A(B,0);
			For(t,0,1<<16) C[t]=1ll*A[t]*B[t]%p;
			FWT_A(C,1);
			For(t,0,1<<16) U(f[x][t],C[t]);
		}
	}
	return x;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	m=IN();
	For(t,0,m){
		For(i,0,4) w[t]|=IN()<<i;
		v[t]=IN();
	}
	Work(1,n);
	For(t,0,1<<16){
		int b=1;
		For(i,0,m){
			if ((t>>w[i]&1)!=v[i]) {b=0;break;}
		}
		if (b) res=(res+f[1][t])%p;
	}
	printf("%d\n",res);
}