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
const int oo=(1<<30)-1;

bitset<N> B[26],tmp;
char s[N],t[N];
int n,q,m,k;

int main(){
	scanf("%s",s);
	n=strlen(s);
	For(i,0,n) B[s[i]-'a'][i]=1;
	q=IN();
	while (q--){
		k=IN();
		scanf("%s",t);
		m=strlen(t);
		tmp.set();
		For(i,0,m) tmp&=B[t[i]-'a']>>i;
		if (tmp.count()<k){
			puts("-1");
			continue;
		}
		Vi V;
		for (int i=tmp._Find_first();i<n;i=tmp._Find_next(i)) V.pb(i);
		int ans=oo;
		for (int i=0;i+k-1<V.size();i++){
			ans=min(ans,V[i+k-1]-V[i]+m);
		}
		printf("%d\n",ans);
	}
}