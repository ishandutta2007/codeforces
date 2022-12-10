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

char s[N],t[N];
int A[N],B[N],C[N],D[N],las[N],las2[N];
int n,m,a,b,c,d,q;

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	For(i,1,n+1){
		A[i]=A[i-1]+(s[i]!='A');
		C[i]=C[i-1]+(s[i]=='A');
		las[i]=(s[i]!='A'?i:las[i-1]);
	}
	For(i,1,m+1){
		B[i]=B[i-1]+(t[i]!='A');
		D[i]=D[i-1]+(t[i]=='A');
		las2[i]=(t[i]!='A'?i:las2[i-1]);
	}
	q=IN();
	while (q--){
		a=IN(),b=IN(),c=IN(),d=IN();
		if (A[b]-A[a-1]>B[d]-B[c-1]||(A[b]-A[a-1])%2!=(B[d]-B[c-1])%2){
			printf("0");
		} else{
			int l=a,r=las[b];
			if (r<l) r=l-1;
			int y=C[b]-C[r];
			int l2=c,r2=las2[d];
			if (r2<l2) r2=l2-1;
			int y2=D[d]-D[r2];
			if (A[b]-A[a-1]==B[d]-B[c-1]){
				if (y>=y2&&y%3==y2%3){
					printf("1");
				} else{
					printf("0");
				}
			} else{
				if (y>y2||y==y2&&A[b]-A[a-1]>0){
					printf("1");
				} else{
					printf("0");
				}
			}
		}
	}
	puts("");
}
/*
AAA
BBAAA
1
1 3 1 5
*/