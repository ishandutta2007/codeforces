// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef pair<ld,ld> pld;

const int maxn=21e5+10,TW=2097152,twl=21;
const ld pi=3.141592653589793238462643383279;

pld operator*(pld a,pld b) { return {a.F*b.F-a.S*b.S,a.F*b.S+a.S*b.F}; }
pld operator+(pld a,pld b) { return {a.F+b.F,a.S+b.S}; }
pld operator-(pld a,pld b) { return {a.F-b.F,a.S-b.S}; }

pld w[maxn],tmp[maxn];
int REV[maxn];

void pre(){
    w[0]={1,0};
    w[1]={cos(2*pi/TW),sin(2*pi/TW)};
    for(int i=2;i<=TW;i++)
	w[i]=w[1]*w[i-1];
    for(int msk=1;msk<TW;msk++){
	int num=0;
	for(int i=0;i<twl;i++){
	    if(bit(msk,i))
		num+=(1<<(twl-1-i));
	    REV[msk]=num;
	}
    }
}

void bit_reverse(pld *a){
    for(int i=0;i<TW;i++)
	tmp[i]=a[REV[i]];
    for(int i=0;i<TW;i++)
	a[i]=tmp[i];
}

void fft(pld *a,bool rev){
    bit_reverse(a);
    for(int ln=1;ln<TW;ln*=2){
	int step=(TW/(2*ln));
	for(int st=0;st<TW;st+=ln+ln){
	    for(int i=0;i<ln;i++){
		pld x=a[st+i+ln]*w[(rev?-1:1)*step*i+(rev?TW:0)];
		a[st+i+ln]=a[st+i]-x;
		a[st+i]=a[st+i]+x;
	    }
	}
    }
    if(rev){
	for(int i=0;i<TW;i++)
	    a[i].F/=TW;
    }
}

pld p[maxn];
bool q1[maxn],q2[maxn];
vector<int>ans;

int main(){
    pre();
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
	int x;scanf("%d",&x);
	p[x].F=q1[x]=1;
    }
    fft(p,0);
    for(int i=0;i<TW;i++)
	p[i]=p[i]*p[i];
    fft(p,1);
    for(int i=0;i<TW;i++)
	q2[i]=ll(p[i].F+0.5)>0;
    for(int i=0;i<=m;i++){
	if(!q1[i] && q2[i]){
	    printf("NO\n");
	    return 0;
	}
	if(q1[i] && !q2[i]){
	    ans.PB(i);
	}
    }
    printf("YES\n%d\n",sz(ans));
    for(int x:ans)
	printf("%d ",x);
    printf("\n");
}