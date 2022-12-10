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

char s[100];
int n,ans;

bool check(int l,int r){
	for (int i=l,j=r;i<=j;i++,j--)
		if (s[i]!=s[j]) return 1;
	return 0;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n+1) For(j,i+1,n+1){
		if (check(i,j)) ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
}