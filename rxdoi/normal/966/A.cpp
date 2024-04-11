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

const int oo=(1<<30)-1;

Vi A,B;
int n,m,ca,cb,v,ans,X1,Y1,X2,Y2;

int calcA(int Y){
	if (Y==0||Y==m+1) return oo;
	return abs(Y1-Y)+abs(Y2-Y)+abs(X1-X2);
}
int calcB(int Y){
	if (Y==0||Y==m+1) return oo;
	return abs(Y1-Y)+abs(Y2-Y)+(abs(X1-X2)/v+(abs(X1-X2)%v!=0));
}

int main(){
	n=IN(),m=IN(),ca=IN(),cb=IN(),v=IN();
	A.pb(0);
	A.pb(m+1);
	B.pb(0);
	B.pb(m+1);
	For(i,1,ca+1) A.pb(IN());
	For(i,1,cb+1) B.pb(IN());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for (int q=IN();q--;){
		X1=IN(),Y1=IN(),X2=IN(),Y2=IN();
		ans=oo;
		if (X1==X2) ans=min(ans,abs(Y1-Y2));
		ans=min(ans,calcA(A[lower_bound(A.begin(),A.end(),Y1)-A.begin()]));
		ans=min(ans,calcA(A[upper_bound(A.begin(),A.end(),Y1)-A.begin()-1]));
		ans=min(ans,calcA(A[lower_bound(A.begin(),A.end(),Y2)-A.begin()]));
		ans=min(ans,calcA(A[upper_bound(A.begin(),A.end(),Y2)-A.begin()-1]));
		ans=min(ans,calcB(B[lower_bound(B.begin(),B.end(),Y1)-B.begin()]));
		ans=min(ans,calcB(B[upper_bound(B.begin(),B.end(),Y1)-B.begin()-1]));
		ans=min(ans,calcB(B[lower_bound(B.begin(),B.end(),Y2)-B.begin()]));
		ans=min(ans,calcB(B[upper_bound(B.begin(),B.end(),Y2)-B.begin()-1]));
		printf("%d\n",ans);
	}
}