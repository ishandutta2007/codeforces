#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2005;
const int L = 4e6+5;

int n,m;
int a[N],b[N];
struct section{
	int l,r,v;
	section(const int l_=0,const int r_=0,const int v_=0){l=l_;r=r_;v=v_;}
}A[L],B[L];
int ka,kb;

bool cmp(section a,section b){return a.v<b.v;}

int px[L];

int main(){
	n=get();m=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,m)b[i]=get();
	fo(l,1,n){
		for(int sum=0,r=l;r<=n;r++){
			sum+=a[r];
			A[++ka]=section(l,r,sum);
		}
	}
	fo(l,1,m){
		for(int sum=0,r=l;r<=m;r++){
			sum+=b[r];
			B[++kb]=section(l,r,sum);
		}
	}
	int l1=0,r1=0,l2=0,r2=0;
	sort(A+1,A+1+ka,cmp);
	sort(B+1,B+1+kb,cmp);
	fo(i,1,kb)px[i]=max(px[i-1],(B[i].r-B[i].l+1));
	int lim=get();
	int w=kb;
	fo(i,1,ka){
		while(w&&1ll*A[i].v*B[w].v>lim)w--;
		if (w&&(A[i].r-A[i].l+1)*px[w]>=(r1-l1+1)*(r2-l2+1)){
			l1=A[i].l,r1=A[i].r;
			l2=1,r2=px[w];
		}
	}
	if (!l1)printf("0\n");
	else printf("%d",(r1-l1+1)*(r2-l2+1));
	return 0;
}