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

const int maxn=15e5+10;
const int TTW=1048576,mod1=7340033,W1=3,mod2=13631489,W2=15;

int tavan(int a,int b,int md){
    int ans=1;
    while(b>0){
	if(b&1) ans=(1ll*ans*a)%md;
	a=(1ll*a*a)%md;
	b/=2;
    }
    return ans;
}

struct NTT{
    int TW,RVT,Mod,W;// size matrice // reverse TW too peimaneye mod // modemoon :) // (peimitive root)^(mod-1 / TW) // 262144 // 786430 // 786433 // 1000
    int w[maxn],arr1[maxn],arr2[maxn];
    
    NTT(int tw,int mod,int ww){
	TW=tw;RVT=tavan(tw,mod-2,mod);Mod=mod;W=tavan(ww,(mod-1)/tw,mod);
	w[0]=1;
	for(int i=1;i<maxn;i++)
	    w[i]=(1ll*w[i-1]*W)%Mod;
    }
    void transform(int *a,bool rev){
	for(int ln=1;ln<TW;ln*=2){
	    int step=TW/(ln*2);
	    for(int st=0;st<step;st++){
		for(int i=0;i<ln;i++){
		    arr1[i]=a[st+2*i*step];
		    arr2[i]=a[st+2*i*step+step];
		}
		for(int i=0;i<ln;i++){
		    int A=arr1[i],B=(1ll*arr2[i]*w[(rev?-1:1)*i*step+(rev?TW:0)])%Mod;
		    a[st+i*step]=(A+B)%Mod;
		    a[st+(i+ln)*step]=(A-B)%Mod;
		}
	    }
	}
	if(rev){
	    for(int i=0;i<TW;i++)
		a[i]=(1ll*a[i]*RVT)%Mod;
	}
    }
};

int cnt1[maxn],cnt2[maxn],n,k;
NTT ntt1(TTW,mod1,W1),ntt2(1048576,mod2,W2);

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	cnt1[x]=cnt2[x]=1;
    }
    ntt1.transform(cnt1,0);
    ntt2.transform(cnt2,0);
    for(int i=0;i<maxn;i++){
	cnt1[i]=tavan(cnt1[i],k,mod1);
	cnt2[i]=tavan(cnt2[i],k,mod2);
    }
    ntt1.transform(cnt1,1);
    ntt2.transform(cnt2,1);
    for(int i=0;i<maxn;i++){
	if(cnt1[i]!=0 || cnt2[i]!=0)
	    printf("%d ",i);
    }
    printf("\n");
}