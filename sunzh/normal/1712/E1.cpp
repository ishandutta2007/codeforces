#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);c=getchar();
	}
	return x;
}
int T;
struct que{
	int l,r,id,k;
};
vector<que>vec[400010];
vector<int>fac[400010];
long long ans[400010];
long long tre[400010];
long long query(int x){
	long long res=0;
	while(x<=400000){
		res+=tre[x];x+=x&-x;
	}
	return res;
}
void upd(int x,int k){
	printf("x:%d,k:%d\n",x,k);
	while(x){
		tre[x]+=k;x-=x&-x;
	}
}
void upd2(int x,int k){
	// printf("x:%d,k:%d\n",x,k);
	while(x){
		tre[x]+=k;x-=x&-x;
	}
}
long long get(int len){
	return 1ll*len*(len-1)*(len-2)/6;
}
int val[400010];
int main(){
	T=read();
	for(int i=1;i<=T;++i){
		int l=read(),r=read();
		vec[r].pb(que{l,r,i,-1});vec[l-1].pb(que{l,r,i,1});
		ans[i]=get(r-l+1);
	}
	for(int i=1;i<=400000;++i){
		for(int j=i+i;j<=400000;j+=i) fac[j].pb(i);
	}
	for(int i=1;i<=200000;++i){
		for(int j=0;j<fac[i].size();++j){
			upd2(fac[i][j],fac[i].size()-j-1);
		}
		int it=-1,res=0;
		for(int j=0;j<fac[2*i].size();++j) if(fac[2*i][j]<i&&(i%fac[2*i][j]==0)){
			while(it+1<fac[i].size()&&i/fac[i][it+1]*2>fac[2*i][j]&&i/fac[i][it+1]*2+fac[2*i][j]>i){
				++it;res+=(fac[i][it]&1)-(fac[i][it]==1);
			}
			while(it>=0&&i/fac[i][it]*2<=fac[2*i][j]){
				res-=(fac[i][it]&1)-(fac[i][it]==1);--it;
			}
			// printf("i:%d,j:%d,%d,it:%d,%d\n",i,j,fac[2*i][j],it,it==-1?-1:fac[i][it]);
			upd2(fac[2*i][j],res);
			// if(i/fac[i][it])
		}
		it=0;
		int it2=fac[2*i].size()-1;
		val[fac[2*i].size()]=0;
		for(int j=fac[2*i].size()-1;j>=0;--j) val[j]=val[j+1]+(fac[2*i][j]<i);
		for(int j=1;j<fac[i].size();++j) if(fac[i][j]&1){
			while(it<fac[2*i].size()&&fac[2*i][it]+i/fac[i][j]*2<=i) ++it;
			while(it2&&fac[2*i][it2-1]>i/fac[i][j]*2) --it2;
			// printf("i:%d,j:%d,%d %d,it:%d,%d,it2:%d,%d\n",i,j,fac[i][j],i/fac[i][j]*2,it,fac[2*i][it],it2,fac[2*i][it2]);
			upd2(i/fac[i][j]*2,val[max(it,it2)]);
			if(fac[2*i][max(it,it2)]<=i/fac[i][j]*2) upd2(i/fac[i][j]*2,-1);
		}
		for(que j:vec[i]){
			// printf("i:%d,%d,%d\n",j.k,)
			ans[j.id]+=j.k*(query(j.l));
		}
	}
	for(int i=1;i<=T;++i) printf("%lld\n",ans[i]);
}