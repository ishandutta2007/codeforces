// Phoenix

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

const int maxn=2e6+10;
const ld pi= 3.141592653589793238462643383279;

pld operator +(pld a,pld b){
    return {a.F+b.F,a.S+b.S};
}
pld operator -(pld a,pld b){
    return {a.F-b.F,a.S-b.S};
}
pld operator *(pld a,pld b){
    return {a.F*b.F-a.S*b.S,a.F*b.S+a.S*b.F};
}

pld a[maxn],b[maxn],ARR[maxn];
int ans[maxn],C;

void fft(pld *arr,int n,bool inv){
    for(int i=0;i<(1<<n);i++){
	int x=0;
	for(int j=0;j<n;j++){
	    if(bit(i,j))
		x+=(1<<(n-1-j));
	}
	ARR[x]=arr[i];
    }
    for(int i=0;i<(1<<n);i++){
	arr[i]=ARR[i];
    }
    int N=(1<<n);
    for(int ln=1;ln<N;ln<<=1){
	int ln2=ln<<1;
	pld w={cos(2*pi*(inv?-1:1)/ln2),sin(2*pi*(inv?-1:1)/ln2)};
 	for(int st=0;st<N;st+=ln2){
	    pld nw={1,0};
	    for(int i=0;i<ln;i++){
		pld x=arr[i+st+ln]*nw,&a=arr[i+st],&b=arr[i+st+ln];
		nw=nw*w;
		b=a-x;
		a=a+x;
		if(inv){
		    a.F/=2;a.S/=2;
		    b.F/=2;b.S/=2;
		}
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	C=0;
	int n;cin>>n;
	int N=0;
	while((1<<N)<n)
	    N++;
	N++;
	pld EMP={0,0};
	fill(a,a+(1<<N),EMP);
	fill(b,b+(1<<N),EMP);
	string s;cin>>s;
	for(int i=0;i<n;i++){
	    if(s[i]=='V')
		a[i]={1,0};
	    if(s[i]=='K')
		b[n-1-i]={1,0};
	}
	fft(a,N,0);
	fft(b,N,0);
	for(int i=0;i<(1<<N);i++)
	    a[i]=a[i]*b[i];
	fft(a,N,1);
	for(int i=1;i<=n;i++){
	    bool is=0;
	    for(int j=i;j<=n;j+=i)
		is|=(ll(a[n-1+j].F+0.5)>0 || ll(a[n-1-j].F+0.5)>0);
	    if(!is)
		ans[C++]=i;
	}
	cout<<C<<endl;
	for(int i=0;i<C;i++)
	    cout<<ans[i]<<" ";
	cout<<"\n";
    }
    return 0;
}