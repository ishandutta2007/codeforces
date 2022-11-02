#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int T,x[4],y[4],s,d,ans,X[2],Y[2],
xt,yt,ax[4],ay[4],tp[4],pe[4],mn,mx,now;
map<int,int>tx,ty;
inline bool chk(map<int,int>&mp,int*v,int&t){
	if(mp.size()>2)return 1;
	t=0;
	for(auto i:mp){
		v[t++]=i.first;
		if(i.second>2)return 1;
	}
	return 0;
}
inline int mov(int X,int Y,int p){
	if(x[p]==X)return abs(y[p]-Y);
	return y[p]==Y?abs(x[p]-X):inf;
}
inline void fd(int X,int Y){
	for(int i=0;i<4;i++)pe[i]=i;
	do{
		now=0;
		now=max(max(mov(X,Y,pe[0]),mov(X+d,Y,pe[1])),
		max(mov(X,Y+d,pe[2]),mov(X+d,Y+d,pe[3])));
		if(now<ans){
			ans=now;
			ax[pe[0]]=ax[pe[2]]=X;
			ax[pe[1]]=ax[pe[3]]=X+d;
			ay[pe[0]]=ay[pe[1]]=Y;
			ay[pe[2]]=ay[pe[3]]=Y+d;
		}
	}while(next_permutation(pe,pe+4));
}
int main(){
//	freopen("dat.txt","r",stdin);
	for(scanf("%d",&T);T--;){
		ans=inf;
		for(int i=0;i<4;i++)
		scanf("%d%d",x+i,y+i);
		for(s=0;s<16;s++){
			tx.clear(),ty.clear();
			for(int i=0;i<4;i++)
			if(s>>i&1)tx[x[i]]++;
			else ty[y[i]]++;
			if(chk(tx,X,xt)||chk(ty,Y,yt)||
			xt==1&&yt==1)continue;
			d=-1;
		//	if(s==2)cerr<<xt<<','<<yt<<endl;
			if(xt==2){
				d=X[1]-X[0];
				if(yt==2){
					if(d!=Y[1]-Y[0])
					continue;
					fd(X[0],Y[0]);
				}
				else if(yt){
					fd(X[0],Y[0]);
					fd(X[0],Y[0]-d);
				}
				else{
					for(int i=1;i<4;i++)
					for(int j=0;j<i;j++){
						mn=1e9,mx=-1e9;
						for(int k=0;k<4;k++)
						mn=min(mn,y[k]-(k==i||k==j)*d),
						mx=max(mx,y[k]-(k==i||k==j)*d);
						fd(X[0],(mn+mx)/2);
					}
				}
			}
			else{
				d=Y[1]-Y[0];
				assert(yt==2);
				if(xt){
					fd(X[0],Y[0]);
					fd(X[0]-d,Y[0]);
				}
				else{
					for(int i=1;i<4;i++)
					for(int j=0;j<i;j++){
						mn=1e9,mx=-1e9;
						for(int k=0;k<4;k++)
						mn=min(mn,x[k]-(k==i||k==j)*d),
						mx=max(mx,x[k]-(k==i||k==j)*d);
						fd((mn+mx)/2,Y[0]);
					}
				}
			}
		}
		if(ans<inf){
			printf("%d\n",ans);
			for(int i=0;i<4;i++)
			printf("%d %d\n",ax[i],ay[i]);
		}else puts("-1");
	}
}