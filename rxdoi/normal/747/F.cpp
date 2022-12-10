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

const int N=50+19;

int A[N];
ll f[N],C[N][N],tmp;
int k,t,len;

ll calc(int l){
	static ll f[N];
	memset(f,0,sizeof(f));
	f[0]=1;
	For(i,0,16){
		for (int j=l;~j;j--)
			for (int k=1;k<=j&&k<=A[i];k++){
				f[j]+=C[j][k]*f[j-k];
			}
	}
	return f[l];
}

int main(){
	For(i,0,N){
		C[i][0]=1;
		For(j,1,i+1) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	scanf("%d%d",&k,&t);
	For(l,1,50){
		For(i,0,16) A[i]=t;
		For(i,1,16){
			A[i]--;
			f[l]+=calc(l-1);
			A[i]++;
		}
	}
	For(l,1,50)
		if (k<=f[l]){
			len=l;break;
		} else{
			k-=f[l];
		}
	For(i,0,16) A[i]=t;
	For(i,1,len+1){
		For(j,i==1,16)
			if (A[j]){
				A[j]--;
				tmp=calc(len-i);
				if (k<=tmp){
					putchar("0123456789abcdef"[j]);
					break;
				}
				k-=tmp;
				A[j]++;
			}
	}
	puts("");
}