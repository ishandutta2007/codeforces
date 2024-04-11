#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
mt19937 rnd(time(0));
char c[10];
int T,n,m,ans,v[1010],p;
IN Rand(int Mod){
	re res=rnd();if(res<0)res=-res;res%=Mod;return res;
}
I getit(int x,int y,int len){
	if(x==y)return cout<<"! "<<x<<endl,void();
	re mid=(x+y)>>1,ln=(len+1)>>1;
	cout<<"? "<<ln<<" "<<ln<<endl;
	F(i,x-ln,x-1)cout<<i<<" ";cout<<endl;
	F(i,x,mid)cout<<i<<" ";cout<<endl;
	cout.flush();cin>>c+1;if(c[1]=='W')exit(0);
	if(c[1]=='F')getit(x,mid,ln);
	else getit(mid+1,y,len-ln);
}
int main(){
	srand(time(0));
	cin>>T;
	while(T--){
		cin>>n>>m;C(v,0);ans=0;
		F(i,1,min(30,n-1)){
			while(1){
				p=Rand(n-1)+2;if(!v[p])break;
			}
			v[p]=1;
			cout<<"? 1 1"<<endl<<"1"<<endl<<p<<endl;cout.flush();
			cin>>c+1;if(c[1]=='W')return 0;
			if(c[1]=='S'){ans=1;break;}	
		}
		if(ans){cout<<"! "<<ans<<endl;cout.flush();continue;}
		re r=1,mid;
		while((r<<1)<=n){
			r<<=1;mid=r>>1;cout<<"? "<<mid<<" "<<mid<<endl;
			F(i,1,mid)cout<<i<<" ";cout<<endl;
			F(i,mid+1,r)cout<<i<<" ";cout<<endl;
			cout.flush();cin>>c+1;if(c[1]=='W')return 0;
			if(c[1]=='F'){
				getit(mid+1,r,mid);ans=1;
				break;
			}
		}
		if(ans)continue;
		getit(r+1,n,n-r);
	}
	return 0;
}