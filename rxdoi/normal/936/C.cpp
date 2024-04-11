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

const int N=2000+19;

char s[N],t[N];
int cnt[26];
int n;
Vi V;

int main(){
	n=IN();
	scanf("%s",s+1);
	scanf("%s",t+1);
	For(i,1,n+1) cnt[s[i]-'a']++;
	For(i,1,n+1) cnt[t[i]-'a']--;
	For(i,0,26) if (cnt[i]){
		puts("-1");
		return 0;
	}
	For(i,1,n+1){
		int x;
		for (int j=1;j<=n-i+1;j++)
			if (s[j]==t[i]){
				x=j;
				break;
			}
		V.pb(n-x);
		V.pb(1);
		V.pb(n);
		reverse(s+1,s+x);
		For(j,x,n) s[j]=s[j+1];
		s[n]=t[i];
	}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);
	puts("");
}