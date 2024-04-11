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

const int N=100000+19;
const int oo=(1<<30)-1;

int A[N],val[N],stk[N],pre[N],suf[N];
int n,Qc,l,r,res;
ll sum;

void Init(){
	val[0]=oo;
	stk[*stk=1]=0;
	for (int i=1;i<n;i++){
		while (val[i]>val[stk[*stk]]) (*stk)--;
		pre[i]=stk[*stk];
		stk[++*stk]=i;
	}
	val[n]=oo;
	stk[*stk=1]=n;
	for (int i=n-1;i;i--){
		while (val[i]>=val[stk[*stk]]) (*stk)--;
		suf[i]=stk[*stk];
		stk[++*stk]=i;
	}
}

int main(){
	n=IN(),Qc=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n) val[i]=abs(A[i]-A[i+1]);
	Init();
	while (Qc--){
		sum=0;
		l=IN(),r=IN()-1;
		For(i,l,r+1){
			sum+=1ll*val[i]*(i-max(pre[i],l-1))*(min(suf[i],r+1)-i);
		}
		printf("%I64d\n",sum);
	}
}