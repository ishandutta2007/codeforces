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

const int maxn=6e5+10,TW=524288;
const ld pi=3.141592653589793238462643383279;

pld operator*(pld a,pld b) { return {a.F*b.F-a.S*b.S,a.F*b.S+a.S*b.F}; }
pld operator+(pld a,pld b) { return {a.F+b.F,a.S+b.S}; }
pld operator-(pld a,pld b) { return {a.F-b.F,a.S-b.S}; }

pld cnt1[maxn],cnt2[maxn],w[maxn],arr1[maxn],arr2[maxn];

int sm[maxn];
ll ans[maxn];

void pre(){
    w[0]={1,0};
    w[1]={cos(2*pi/TW),sin(2*pi/TW)};
    for(int i=2;i<=TW;i++)
	w[i]=w[1]*w[i-1];
}

void fft(pld *a,bool rev){
    for(int ln=1;ln<TW;ln*=2){
	int step=(TW/(2*ln));
	for(int st=0;st<step;st++){
	    for(int i=0;i<ln;i++){
		arr1[i]=a[st+2*i*step];
		arr2[i]=a[st+2*i*step+step];
	    }
	    for(int i=0;i<ln;i++){
		pld A=arr1[i],B=arr2[i]*w[(rev?-1:1)*step*i+(rev?TW:0)];
		a[st+i*step]=A+B;
		a[st+(i+ln)*step]=A-B;
	    }
	}
    }
    if(rev){
	for(int i=0;i<TW;i++)
	    a[i].F/=TW;
    }
}

int main(){
    pre();
    int n,X;scanf("%d%d",&n,&X);
    for(int i=1;i<=n;i++){
	int x;scanf("%d",&x);
	sm[i]=sm[i-1]+(x<X);
    }
    for(int i=0;i<=n;i++){
	cnt1[sm[i]].F++;
	cnt2[TW/2-sm[i]].F++;
    }
    fft(cnt1,0);
    fft(cnt2,0);
    for(int i=0;i<TW;i++)
	cnt1[i]=cnt1[i]*cnt2[i];
    fft(cnt1,1);
    for(int i=0;i<(TW/2);i++)
	ans[i]=ll(cnt1[i+(TW/2)].F+0.5);
    ans[0]=(ans[0]-n-1)/2;
    for(int i=0;i<=n;i++)
	printf("%lld ",ans[i]);
    printf("\n");
}