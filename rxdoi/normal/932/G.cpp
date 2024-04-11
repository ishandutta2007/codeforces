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

const int N=2e6+19;
const int p=1e9+7;

char s[N],t[N];
int dp[N];
int n;

struct node{
	node *go[26],*fail,*anc;
	int len,diff,val;
} Nd[N],*cur=Nd,*r0,*r1,*las;

node *New(int len){
	return cur->len=len,cur++;
}
node *Extend(node *p,int x,int n){
	for (;p&&s[n-1-p->len]!=s[n];p=p->fail);
	if (p->go[x]) return p->go[x];
	node *np=New(p->len+2);
	p->go[x]=np;
	if (p==r1){
		np->fail=r0;
	} else{
		for (p=p->fail;s[n-1-p->len]!=s[n];p=p->fail);
		np->fail=p->go[x];
	}
	np->diff=np->len-np->fail->len;
	np->anc=(np->diff==np->fail->diff?np->fail->anc:np->fail);
	return np;
}

int main(){
	las=r0=New(0);
	r1=New(-1);
	r0->fail=r1;
	scanf("%s",t+1);
	n=strlen(t+1);
	For(i,1,n/2+1){
		s[2*i-1]=t[i];
		s[2*i]=t[n-i+1];
	}
	dp[0]=1;
	For(i,1,n+1){
		las=Extend(las,s[i]-'a',i);
		for (node *u=las;u!=r0;u=u->anc){
			u->val=dp[i-u->anc->len-u->diff];
			if (u->diff==u->fail->diff){
				u->val=(u->val+u->fail->val)%p;
			}
			if (i%2==0) dp[i]=(dp[i]+u->val)%p;
		}
	}
	printf("%d\n",dp[n]);
}