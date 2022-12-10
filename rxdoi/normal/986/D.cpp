#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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

const int L=2000000;
const int Base=10000;
const db pi=acos(-1.0);

struct comp{
	db r,i;
} w[2][L],F[L],G[L];
char str[1500000+19];
int rev[L];
int c;

comp operator + (comp A,comp B){
	return (comp){A.r+B.r,A.i+B.i};
}
comp operator - (comp A,comp B){
	return (comp){A.r-B.r,A.i-B.i};
}
comp operator * (comp A,comp B){
	return (comp){A.r*B.r-A.i*B.i,A.r*B.i+A.i*B.r};
}

void Prepare(int n){
	For(i,0,n){
		w[0][i]=w[1][i]=(comp){cos(2*pi*i/n),sin(2*pi*i/n)};
		w[1][i].i*=-1;
	}
	int m=0;
	while ((1<<m)!=n) m++;
	For(i,1,n) rev[i]=(rev[i>>1]>>1)|(i&1)<<m-1;
}
void FFT(comp *A,int n,int f){
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				comp x=A[k],y=w[f][l]*A[k+i];
				A[k]=x+y;
				A[k+i]=x-y;
			}
	if (f){
		For(i,0,n) A[i].r/=n;
	}
}

struct Bigint{
	int s[L];
	int len;
	Bigint(){}
	Bigint(int v){
		len=0;
		while (len==0||v) s[len++]=v%Base,v/=Base;
	}
	void clr(){
		while (len>1&&!s[len-1]) len--;
	}
	void IN(){
		scanf("%s",str);
		len=0;
		for (int l=strlen(str)-4;l+4>0;l-=4){
			For(i,max(l,0),l+4) s[len]=(s[len]*10+str[i]-'0');
			len++;
		}
		clr();
	}
	void operator += (int B){
		For(i,0,3) s[len++]=0;
		s[0]+=B;
		For(i,0,len)
			if (s[i]>=Base){
				s[i+1]+=s[i]/Base;
				s[i]%=Base;
			} else{
				break;
			}
		clr();
	}
	void operator *= (int B){
		For(i,0,3) s[len++]=0;
		ll tmp=0;
		For(i,0,len){
			tmp+=1ll*s[i]*B;
			s[i]=tmp%Base;
			tmp/=Base;
		}
		clr();
	}
	void operator /= (int B){
		ll tmp=0;
		for (int i=len-1;~i;i--){
			tmp=(tmp*Base+s[i]);
			s[i]=tmp/B;
			tmp%=B;
		}
		clr();
	}
	bool operator < (const Bigint &B) const{
		if (len!=B.len) return len<B.len;
		for (int i=len-1;~i;i--) if (s[i]!=B.s[i]) return s[i]<B.s[i];
		return 0;
	}
} n1,n2,n3,tmp;

int q,ans;

Bigint operator * (const Bigint &A,const Bigint &B){
	static Bigint C;
	for (c=1;c<A.len||c<B.len;c<<=1);c<<=1;
	Prepare(c);
	For(i,0,A.len) F[i]=(comp){A.s[i],0};
	For(i,0,B.len) G[i]=(comp){B.s[i],0};
	For(i,A.len,c) F[i]=(comp){0,0};
	For(i,B.len,c) G[i]=(comp){0,0};
	FFT(F,c,0);
	FFT(G,c,0);
	For(i,0,c) F[i]=F[i]*G[i];
	FFT(F,c,1);
	C.len=c;
	ll tmp=0;
	For(i,0,c){
		tmp+=ll(F[i].r+0.5);
		C.s[i]=tmp%Base;
		tmp/=Base;
	}
	C.clr();
	return C;
}
Bigint Pow(int a,int b){
	static Bigint res,A;
	res=1;
	A=a;
	for (;b;b>>=1,A=A*A) if (b&1) res=res*A;
	return res;
}

int main(){
	n1.IN();
	n2=n1;n2+=1;n2/=2;
	n3=n2;n3+=1;n3/=2;
	if (n1.len==1&&n1.s[0]==1){
		puts("1");
		return 0;
	}
	q=int(((n3.len-1)*4)/(log(3)/log(10)));
	q=max(q-5,0);
	tmp=Pow(3,q);
	while (tmp<n3) tmp*=3,q++;
	ans=3*q+4;
	while (tmp<n2) tmp*=3,q++;
	ans=min(ans,3*q+2);
	while (tmp<n1) tmp*=3,q++;
	ans=min(ans,3*q);
	printf("%d\n",ans);
}