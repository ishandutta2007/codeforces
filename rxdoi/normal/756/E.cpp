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
const int oo=(1<<30)-1;
const int p=1e9+7;

int dp[2][20*N],mx[2];
int A[N],b[N],c[N],s[N];
int n,l,t,len;
char str[N];

void upd(int t,int x,int v){
//	assert(x<20*N);
	dp[t][x]=(dp[t][x]+v)%p;
	if (x>mx[t]) mx[t]=x;
}
void Div(int x,int &rem){
	ll tmp=0;
	for (int i=l;i;i--){
		tmp=(tmp*1000000000+s[i]);
		s[i]=tmp/x;
		tmp%=x;
	}
	rem=tmp;
	while (l>1&&!s[l]) l--;
}

int main(){
	n=IN();
	A[1]=1;
	For(i,2,n+1) A[i]=IN();
	For(i,1,n+1) b[i]=IN();
	scanf("%s",str+1);
	len=strlen(str+1);
	reverse(str+1,str+len+1);
	l=len/9+(len%9!=0);
	For(i,1,l+1){
		for (int j=min(i*9,len);j>(i-1)*9;j--){
			s[i]=(s[i]*10+str[j]-'0');
		}
	}
	A[n+1]=oo;
	For(i,1,n+1) if (A[i+1]>1) Div(A[i+1],c[i]);
	if (l!=1||s[1]!=0){
		puts("0");
		return 0;
	}
	dp[t][0]=1;
	dp[t][1]=p-1;
	mx[t]=1;
	For(i,1,n+1){
		For(j,1,mx[t]+1){
			dp[t][j]=(dp[t][j]+dp[t][j-1])%p;
		}
		For(j,0,mx[t]+1) if (dp[t][j]){
			int k=(c[i]-j%A[i+1]+A[i+1])%A[i+1];
			int l=(j+k-c[i])/A[i+1],r=b[i]/A[i+1]+1-(b[i]%A[i+1]<k);
			upd(t^1,l,dp[t][j]);
			upd(t^1,l+r,p-dp[t][j]);
			/*
			For(u,0,r){
				upd(t^1,l+u,dp[t][j]);
			}
			*/
			dp[t][j]=0;
		}
		mx[t]=0;
		t^=1;
	}
	printf("%d\n",dp[t][0]);
}