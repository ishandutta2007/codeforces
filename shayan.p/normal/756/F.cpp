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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int aft[maxn],tn1[maxn],tn2[maxn];
vector<pair<int,pii> >vec;

int Pow(int a,int b){
    b=((b%(mod-1))+mod-1)%(mod-1);
    a=((a%mod)+mod)%mod;
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod)
	if(b&1)
	    ans=1ll*ans*a %mod;
    return ans;
}
pii operator + (pii a,pii b){
    return {(1ll*Pow(10,b.S)*a.F+b.F)%mod,(a.S+b.S)%(mod-1)};
}
int ff(pii a,int dig){
    int R1=(a.F+1)%mod,R2=(a.S+1)%(mod-1);
    int num=Pow(Pow(10,dig)-1,mod-2),ANS=0;
    if(num==0) ANS=1ll*R1*(R1-1) %mod *Pow(2,mod-2) %mod;
    else ANS=1ll*((1ll*(Pow(10,1ll*dig*R2 %(mod-1))-1)*num-R1)%mod)*num %mod;
    return ANS;
}
pii f(pii a,pii b,int dig){
    int A=(1ll*ff(b,dig)-1ll*Pow(10,1ll*dig*(b.S-a.S+1) %(mod-1))*ff({a.F-1,a.S-1},dig))%mod;
    int B=1ll*dig*(b.S-a.S+1) %(mod-1);
    return {A,B};
}
pii operator - (pair<int,pii>a,pair<int,pii>b){
    pii Ans={0,0},nw=a.S;
    for(int i=a.F;i<b.F;i++){
	pii x={tn1[i],tn2[i]};
	Ans=Ans+f(nw,{(x.F+mod-1)%mod,(x.S+mod-2)%(mod-1)},i);
	nw=x;
    }
    Ans=Ans+f(nw,b.S,b.F);
    return Ans;
}
pii operator * (pair<int,pii>a,pii b){
    int x=b.F,dig=b.S,Num1=a.S.F,Num2=a.S.S,Ans=0;
    if(Pow(10,dig)==1){
	Ans=1ll*Num1*x %mod;
    }
    else{
	Ans=1ll* (Pow(10,1ll*dig*Num2 %(mod-1))-1) * (Pow(Pow(10,dig)-1,mod-2)) %mod *x %mod;
    }
    return {Ans,1ll*Num2*dig %(mod-1)};
}

pii solve(int l,int r){
    pii Ans={0,0};
    for(int i=l;i<r;i++){
	if(vec[i].F>=0 && i+1!=r && vec[i+1].F<0) continue;
	if(vec[i].F>=0) Ans=Ans+(pii){vec[i].S.F,vec[i].F};
	else if(vec[i].F==-1) Ans=Ans+(vec[i-1]*solve(i+1,aft[i])),i=aft[i];
	else if(vec[i].F==-3) Ans=Ans+(vec[i-1]-vec[i+1]),++i;
    }
    return Ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    tn1[0]=tn2[0]=1;
    for(int i=1;i<maxn;i++)
	tn1[i]=10ll*tn1[i-1] %mod,tn2[i]=10ll*tn2[i-1] %(mod-1);
    string str;cin>>str;
    for(int i=0;i<sz(str);i++){
	if(str[i]=='('){
	    vec.PB({-1,{0,0}});
	}
	else if(str[i]==')'){
	    vec.PB({-2,{0,0}});
	}
	else if(str[i]=='-'){
	    vec.PB({-3,{0,0}});
	}
	else if(str[i]!='+'){
	    int A=0,B=0,C=0;
	    while(i<sz(str) && '0'<=str[i] && str[i]<='9'){
		A=(1ll*10*A+(str[i]-'0'))%mod;
		B=(1ll*10*B+(str[i]-'0'))%(mod-1);
		C++,i++;
	    }
	    vec.PB({C,{A,B}});
	    --i;
	}
    }
    memset(aft,-1,sizeof aft);
    vector<int>vec2;
    for(int i=0;i<sz(vec);i++){
	if(vec[i].F==-1) vec2.PB(i);
	if(vec[i].F==-2) aft[vec2.back()]=i,vec2.pop_back();
    }
    int Ans=solve(0,sz(vec)).F;
    if(Ans<0) Ans+=mod;
    return cout<<Ans<<endl,0;
}