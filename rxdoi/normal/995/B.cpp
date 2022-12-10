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

const int N=1000+19;

int A[N],s[N];
int n,ans;

int main(){
	n=IN();
	For(i,1,2*n+1) A[i]=IN(),s[i]=1;
	For(i,1,2*n+1) if (s[i]){
		for (int j=i+1;j<=2*n;j++){
			if (A[i]==A[j]){
				s[i]=s[j]=0;
				break;
			}
			ans+=s[j];
		}
	}
	printf("%d\n",ans);
}