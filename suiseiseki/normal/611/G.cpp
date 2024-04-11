#include <cstdio>
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
template<typename Elem>
Elem abs(Elem a){
	return a<0?-a:a;
}
typedef long long ll;
const int Maxn=500000,Mod=1000000007;
const int inv_4=(Mod+1)>>2;
int n;
struct Node{
	ll x,y;
	friend Node operator +(Node a,Node b){
		Node ans;
		ans.x=a.x+b.x;
		ans.y=a.y+b.y;
		return ans;
	}
	friend Node operator -(Node a,Node b){
		Node ans;
		ans.x=a.x-b.x;
		ans.y=a.y-b.y;
		return ans;
	}
	friend ll operator *(Node a,Node b){
		return a.x*b.y-a.y*b.x;
	}
	void mod(){
		x%=Mod;
		y%=Mod;
	}
}a[Maxn+5],s_1[Maxn+5];
ll s_2[Maxn+5],s_3[Maxn+5];
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].x),read(a[i].y);
		s_1[i]=s_1[i-1]+a[i];
		s_1[i].mod();
	}
	for(int i=2;i<=n;i++){
		s_2[i]=a[i-1]*a[i];
		s_2[i]+=s_2[i-1];
		s_3[i]=(s_3[i-1]+s_2[i])%Mod;
	}
	s_2[n+1]=s_2[n]+a[n]*a[1];
	ll S=abs(s_2[n+1]);
	ll ans=0;
	for(int l=1,r=3;r<=n;r++){
		while(l<r-1&&S/2.0<abs(s_2[r]-s_2[l]+a[r]*a[l])){
			l++;
		}
		ans=(ans+s_2[r]%Mod*(r-l-1)-s_3[r-2]+s_3[l-1]+a[r]*(s_1[r-2]-s_1[l-1]))%Mod;
		ans=(ans+s_3[l-1]+s_1[l-1]*a[r]+(s_2[n+1]-s_2[r])%Mod*(l-1))%Mod;
	}
	printf("%lld\n",(((1ll*S%Mod*inv_4%Mod*n%Mod*(n-3)%Mod+ans)%Mod+Mod)<<1)%Mod);
	return 0;
}