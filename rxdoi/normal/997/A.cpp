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

const int N=300000+19;

int n,x,y,m;
char s[N];

int main(){
	n=IN(),x=IN(),y=IN();
	scanf("%s",s+1);
	for (int l=1,r;l<=n;l=r+1){
		for (r=l;r+1<=n&&s[r+1]==s[l];r++);
		if (s[l]=='0') m++;
	}
	if (m==0){
		puts("0");
	} else{
		ll ans=y+1ll*(m-1)*min(x,y);
		cout<<ans<<endl;
	}
}