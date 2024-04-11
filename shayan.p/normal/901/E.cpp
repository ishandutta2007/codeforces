// Wanna Hack? GL...

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

const int MLog=19,Tw=1<<MLog,maxn=Tw+10;
const ll lim=1e9;// isnt enough?
const ll lim2=1e8;//

ll a[maxn],b[maxn],c[maxn],dif[maxn],A[maxn],B[maxn],C[maxn],Mod,G,Log;
int n,N;

ll arr2[maxn];
ll w[2][maxn];
int pos[maxn];

ll Mul(ll a,ll b){
    a%=Mod,b%=Mod;
    ll ans=a*b-ll((ld)a*b/Mod)*Mod;
    return ans;
}
ll Pow(ll a,ll b){
    b%=Mod-1;
    ll ans=1;
    for(;b;b>>=1,a=Mul(a,a)){
	if(b&1) ans=Mul(ans,a);
    }
    return ans;
}
void prep(){
    w[0][0]=w[1][0]=1;
    w[0][1]=Pow(G,(Mod-1)/N);
    for(int i=2;i<N;i++)
	w[0][i]=Mul(w[0][i-1],w[0][1]);
    for(int i=1;i<N;i++)
	w[1][N-i]=w[0][i];
    for(int i=1;i<N;i++)
	pos[i]=(pos[i>>1]>>1) | (i&1 ? 1<<(Log-1) : 0);
}
void ntt(ll *a,bool rev){
    for(int i=0;i<N;i++){
	if(i<pos[i])
	    swap(a[i],a[pos[i]]);
    }
    for(int i=0;i<Log;i++){
	for(int msk=0;msk<N;msk++){
	    if(bit(msk,i)){
		ll &A=a[msk ^ (1<<i)],&B=a[msk],Num=Mul(B,w[rev][(msk & ((1<<i)-1))<<(Log-i-1)]);
		B=(A-Num)%Mod;
		A=(A+Num)%Mod;
	    }
	}
    }
    if(rev){
	ll inv=Pow(2,Mod-1-Log);
	for(int i=0;i<N;i++)
	    a[i]=Mul(a[i],inv);
    }
}
void eval(ll *arr1,ll x){
    memset(arr2,0,sizeof arr2);
    for(int i=n;i<N;i++){
	arr1[i]=0;
    }
    for(int i=0;i<n;i++){
	arr1[i]=Mul(arr1[i],Pow(x,1ll*i*i));
    }
    for(int i=-n;i<=n;i++){
	arr2[i+n]=Pow(x,Mod-1-(1ll*i*i %(Mod-1)));
    }
    ntt(arr1,0);
    ntt(arr2,0);
    for(int i=0;i<N;i++){
	arr1[i]=Mul(arr1[i],arr2[i]);
    }
    ntt(arr1,1);
    for(int i=0;i<n;i++){
	arr1[i]=arr1[i+n];
    }
    for(int i=n;i<N;i++){
	arr1[i]=0;
    }
    for(int i=0;i<n;i++){
	arr1[i]=Mul(arr1[i],Pow(x,1ll*i*i));
    }
}
void Eval(ll *arr1,ll x){
    w[0][0]=1;
    for(int i=1;i<n;i++)
	w[0][i]=Mul(w[0][i-1],Mul(x,x));
    for(int i=0;i<n;i++){
	arr2[i]=0;
	for(int j=0;j<n;j++)
	    arr2[i]=(arr2[i]+Mul(arr1[j],w[0][1ll*i*j %n]))%Mod;
    }
    for(int i=0;i<n;i++){
	arr1[i]=arr2[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    #ifdef shayan
    n=100000,N=3*n;
    #endif
    #ifndef shayan
    cin>>n,N=3*n;
    #endif
    while(N & (N-1)) N+=N &-N;
    Log=__builtin_ctzll(N);
    ll step=(1ll*n*N);
    Mod=1+(((lim+step-1)/step) * step);
    bool ok=1;
    do{
	ok=1;
	Mod+=step;
	for(ll i=2;i*i<=Mod;i++){
	    if(Mod%i==0){
		ok=0;
		break;
	    }
	}
    }while(!ok);
    vector<ll>vec;
    ll Num=Mod-1;
    for(ll i=2;i*i<=Num;i++){
	if(Num%i==0){
	    vec.PB(i);
	    while(Num%i==0) Num/=i;
	}
    }
    G=0;
    do{
	++G;
	ok=1;
	for(ll y:vec){
	    if(Pow(G,(Mod-1)/y)==1){
		ok=0;
		break;
	    }
	}
    }while(!ok);
    
    prep();
    #ifndef shayan
    for(int i=0;i<n;i++)
	cin>>b[i],B[i]=b[i]*2;
    reverse(B+1,B+n);
    for(int i=0;i<n;i++)
	cin>>c[i];
    for(int i=0;i<n;i++)
	C[i]=c[(n-1+i)%n]-c[i];
    #endif
    ll g=Pow(G,(Mod-1)/(2*n));
    eval(B,g),eval(C,g);
    for(int i=0;i<n;i++)
	A[i]=Mul(C[i],Pow(B[i],Mod-2));
    eval(A,Pow(g,Mod-2));
    for(int i=0;i<n;i++){
	dif[i]=(Mul(A[i],Pow(n,Mod-2))+Mod)%Mod;
	if(dif[i]>lim2) dif[i]=dif[i]-Mod;
    }
    for(int i=2;i<n;i++)
	dif[i]+=dif[i-1];
    dif[0]=0;
    ll C2=0,C1=0,C0=-c[0];
    for(int i=0;i<n;i++){
	ll aa=dif[i]-b[i];
	C2++,C1+=2*aa,C0+=aa*aa;
    }
    ll delta=C1*C1-4*C0*C2;
    if(delta<0) return cout<<0<<endl,0;
    ll SQ=sqrt(delta);
    if(SQ*SQ!=delta) return cout<<0<<endl,0;
    vector<ll>ans;
    if((-C1-SQ)%(2*C2)==0) ans.PB((-C1-SQ)/(2*C2));
    if((-C1+SQ)%(2*C2)==0) ans.PB((-C1+SQ)/(2*C2));
    if(delta==0 && sz(ans)) ans.pop_back();
    cout<<sz(ans)<<endl;
    for(int j=0;j<sz(ans);j++){
	for(int i=0;i<n;i++)
	    cout<<ans[j]+dif[i]<<" ";
	cout<<endl;
    }
    return 0;
}