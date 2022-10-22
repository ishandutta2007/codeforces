#include <bits/stdc++.h>

using namespace std;
using num=unsigned long long;
const num mod=(1LL<<58);

const int B=10;
const int SZ=(B+1)/2; //B=5
using elem=array<num,SZ>;

elem operator +(const elem& a,const elem& b){
	elem c={0};
	for(int i=0;i<SZ;++i)c[i]=a[i]+b[i];
	return c;
}

elem operator -(const elem& a,const elem& b){
	elem c={0};
	for(int i=0;i<SZ;++i)c[i]=a[i]-b[i];
	return c;
}

elem operator *(const elem& a,const elem& b){
	elem c={0};
	for(int i=0;i<SZ;++i)
		for(int j=0;j<SZ;++j)
			if(i+j<SZ)c[i+j]+=a[i]*b[j];
			else c[i+j-SZ]-=a[i]*b[j];
	return c;
}
constexpr num pw(num a,num b){
	num c=1;
	for(;b;a*=a,b/=2)if(b&1)c*=a;
	return c;
}
elem pw1(elem a,num b){
	elem c={1};
	for(;b;a=a*a,b/=2)if(b&1)c=c*a;
	return c;
}
const int LG=5;
const int MX=pw(B,LG);
using arr=array<elem,MX>;
int pws[LG+1];
void initpw(){
	pws[0]=1;
	for(int i=0;i<LG;++i)pws[i+1]=pws[i]*B;
}bool tr=(initpw(),1);
int bit(int i, int b){
	return i%pws[b+1]/pws[b];
}
using smarr=array<elem,B>;
elem root={0,1};
elem root1={0,0,0,0,(num)-1};
ostream& operator<<(ostream&a, elem b){
	for(int i=0;i<SZ;++i){
		a<<b[i];
		if(i+1<SZ)a<<' ';
	}
	return a;
}
elem rts[B][B];
elem rts1[B][B];
void initrts(){
	elem cur={1};
	for(int i=0;i<B;++i,cur=cur*root){
		elem kek={1};
		for(int j=0;j<B;++j,kek=kek*cur)
			rts[i][j]=kek;
	}
	cur={1};
	for(int i=0;i<B;++i,cur=cur*root1){
		elem kek={1};
		for(int j=0;j<B;++j,kek=kek*cur)
			rts1[i][j]=kek;
	}
} bool aeou=(initrts(),1);
inline smarr smfft(smarr x,bool inv){
	smarr ans={0};
	elem cur={1};
	for(int i=0;i<B;++i){
		elem kek={1};
		for(int j=0;j<B;++j,kek=kek*cur)
			ans[i]=ans[i]+(inv?rts[i][j]:rts1[i][j])*x[j];
	}
	return ans;
}
void adamar(arr& a,bool inv){
	for(int i=0;i<LG;++i){
		for(int j=0;j<MX;++j){
			if(bit(j,i)==0){
				smarr kek;
				for(int k=0;k<B;++k)
					kek[k]=a[j+pws[i]*k];
				kek=smfft(kek,inv);
				for(int k=0;k<B;++k)
					a[j+pws[i]*k]=kek[k];
			}
		}
	}
}
void eliminate(elem& x){
	num v=x[4];
	x[4]-=v;
	x[3]+=v;
	x[2]-=v;
	x[1]+=v;
	x[0]-=v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	arr mem;
	fill(mem.begin(),mem.end(),elem{0});
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		++mem[x][0];
	}
	adamar(mem,false);
	for(int i=0;i<MX;++i){
		auto x=mem[i];
		mem[i]=pw1(mem[i],n);
	}
	adamar(mem,true);
	num inv=pw(5,(1ULL<<63)-1);
	inv=pw(inv,LG);
	for(auto&x:mem){
		eliminate(x);
		x[0]>>=LG;
		x[0]*=inv;
	}
	for(int i=0;i<n;++i)cout<<mem[i][0]%mod<<'\n';
	return 0;
}