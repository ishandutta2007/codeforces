#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,k;
char a[1000111],b[1000111];
long long A[1000111],bb[1000111],ww[1000111],sA[1000111],cA[1000111],B[1000111],sB[1000111],cB[1000111],ans;

long long pv(long long a,long long b){
	if (!b)return 1;
	long long r=pv(a,b/2);
	r=r*r%M;
	if (b%2)r=r*a%M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&k);
	if (n<k+k){
		puts("0");
		return 0;
	}
	gets(a);
	for (int i=0;i<n;i++)bb[i+1]=bb[i]+(a[i]=='B');
	for (int i=0;i<n;i++)ww[i+1]=ww[i]+(a[i]=='W');
	for (int i=k-1;i<n;i++){
		if (ww[i+1]-ww[i-k+1])A[i]=0;else{
			A[i]=pv(2,i-k+1-bb[i-k+1]-ww[i-k+1]);
			A[i]=(A[i]-(sA[i]-sA[i-k+1])+M)%M;
			A[i]=(A[i]-cA[i-k+1]+M)%M;
		}
		sA[i+1]=(sA[i]+A[i])%M;
		if (a[i-k+1]=='X')cA[i-k+2]=(cA[i-k+1]*2+A[i-k+1])%M;else 
		cA[i-k+2]=(cA[i-k+1]+A[i-k+1])%M;
	}
	reverse(a,a+n);
	for (int i=0;i<n;i++)bb[i+1]=bb[i]+(a[i]=='B');
	for (int i=0;i<n;i++)ww[i+1]=ww[i]+(a[i]=='W');
	for (int i=k-1;i<n;i++){
		if (bb[i+1]-bb[i-k+1])B[i]=0;else{
			B[i]=pv(2,i-k+1-bb[i-k+1]-ww[i-k+1]);
			B[i]=(B[i]-(sB[i]-sB[i-k+1])+M)%M;
			B[i]=(B[i]-cB[i-k+1]+M)%M;
		}
		sB[i+1]=(sB[i]+B[i])%M;
		if (a[i-k+1]=='X')cB[i-k+2]=(cB[i-k+1]*2+B[i-k+1])%M;else 
		cB[i-k+2]=(cB[i-k+1]+B[i-k+1])%M;
	}
	for (int i=0;i<n;i++)ans=(ans+cA[i+1]*B[n-i-2])%M;
	CC(ans);
	return 0;
}