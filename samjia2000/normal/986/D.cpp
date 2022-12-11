#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int LEN = 1.5e6+10;
const int MAXN = (1<<21)+5;
const int maxn = (1<<21);
const db pi = acos(-1);

struct comp{
	db x,y;
	comp(const db x_=0,const db y_=0){x=x_;y=y_;}
}mi[MAXN],Aa[MAXN],Bb[MAXN];
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp conj(comp a){return comp(a.x,-a.y);}
int N;

void DFT(comp *a){
	for(int i=0,j=0;i<N;i++){
		if (i<j)swap(a[i],a[j]);
		int x=N>>1;
		for(;(j^x)<j;x>>=1)j^=x;
		j^=x;
	}
	for(int i=1,d=1;i<N;i<<=1,d++)
		for(int j=0;j<N;j+=(i<<1))
			for(int k=0;k<i;k++){
				comp l=a[j+k],r=a[i+j+k]*mi[(maxn>>d)*k];
				a[i+j+k]=l-r;
				a[j+k]=l+r;
			}
}

void IDFT(comp *a){
	DFT(a);
	reverse(a+1,a+N);
	fo(i,0,N-1)a[i]=comp(a[i].x/N,a[i].y/N);
}

void prepare(){
	mi[0]=1;
	mi[1]=comp(cos(pi*2/maxn),sin(pi*2/maxn));
	fo(i,2,maxn)mi[i]=comp(cos(pi*2/maxn*i),sin(pi*2/maxn*i));
}


struct number{
	int a[LEN],len;
	int& operator [](int x){return a[x];}
}A,B,C,D,E;
char s[LEN];

void multi(number &a,number &b,number &c){
	N=1;
	while(N<=a.len+b.len-2)N<<=1;
	fo(i,a.len,N)a[i]=0;
	fo(i,b.len,N)b[i]=0;
	fo(i,0,N-1)Aa[i]=Bb[i]=0;
	fo(i,0,max(a.len,b.len)-1)Aa[i]=comp(a[i],b[i]);
	DFT(Aa);
	fo(i,0,N-1){
		comp u=Aa[i],v=Aa[i==0?0:N-i];
		comp a0=(u+conj(v))*comp(0.5,0),b0=(u-conj(v))*comp(0,-0.5);
		Bb[i]=a0*b0;
	}
	IDFT(Bb);
	fo(i,0,c.len)c[i]=0;
	fo(i,0,a.len+b.len-2)c[i]=Bb[i].x+0.3;
	fo(i,0,a.len+b.len-3)
	if (c[i]>99){
		c[i+1]=c[i+1]+c[i]/100;
		c[i]=c[i]%100;
	}
	int w=a.len+b.len-2;
	while(c[w]>99){
		c[w+1]=c[w]/100;
		c[w]=c[w]%100;
		w++;
	}
	c.len=w+1;
}

void multi(number &a,int c){
	fo(i,0,a.len-1)a[i]=a[i]*c;
	fo(i,0,a.len-2){
		a[i+1]=a[i+1]+a[i]/100;
		a[i]=a[i]%100;
	}
	int w=a.len-1;
	while(a[w]>99){
		a[w+1]=a[w]/100;
		a[w]=a[w]%100;
		w++;
	}
	a.len=w+1;
}

bool cmp(number &a,number &b){
	if (a.len!=b.len)return a.len<b.len;
	fd(i,a.len-1,0)
	if (a[i]!=b[i])return a[i]<b[i];
	return 0;
}

int main(){
	prepare();
	scanf("%s",s+1);
	A.len=strlen(s+1);
	fo(i,0,A.len-1)A[i]=s[A.len-i]-'0';
	if (A.len==1&&A[0]==1)return printf("1\n"),0;
	
	fo(i,0,A.len/2){
		A[i]=A[i*2]+A[i*2+1]*10;
	}
	A.len=A.len/2+(A.len&1);
	
	//2 * 0
	int tim=log(100)/log(3)*(A.len-1);
	tim=tim-2;
	if (tim<=0)tim=0;
	B.len=1;
	B[0]=1;
	C.len=1;
	C[0]=3;
	int bt=tim*3,dt=2+tim*3,et=4+tim*3;
	for(;tim;tim/=2,multi(C,C,C))
	if (tim&1)multi(B,C,B);
	D.len=E.len=B.len;
	fo(i,0,B.len-1)E[i]=D[i]=B[i];
	multi(D,2);
	multi(E,4);
	while(cmp(B,A))multi(B,3),bt+=3;
	while(cmp(D,A))multi(D,3),dt+=3;
	while(cmp(E,A))multi(E,3),et+=3;
	printf("%d\n",min(min(bt,dt),et));
	
	return 0;
}