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

char s[N],ch[3],t[N];
bitset<N> F[26],A,B;
int n,m,x,l,r;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n+1){
		F[s[i]-'a'][i]=1;
		A[i]=1;
	}
	for (int q=IN();q--;){
		if (IN()==1){
			x=IN();
			scanf("%s",ch);
			F[s[x]-'a'][x]=0;
			s[x]=ch[0];
			F[s[x]-'a'][x]=1;
		} else{
			l=IN(),r=IN();
			scanf("%s",t+1);
			m=strlen(t+1);
			r=r-m+1;
			if (l>r){
				puts("0");
				continue;
			}
			B=A;
			For(i,1,m+1){
				B&=F[t[i]-'a']>>i-1;
			}
			B=B>>l<<l;
			B=B<<N-1-r;
			printf("%d\n",B.count());
		}
	}
}