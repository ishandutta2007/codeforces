#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define lld I64d
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=100005;
struct po{
	LL x,y;
	inline po(LL _x=0,LL _y=0){
		x=_x;y=_y;
	}
};
inline po operator +(const po &a,const po &b){return po(a.x+b.x,a.y+b.y);}
inline po operator -(const po &a,const po &b){return po(a.x-b.x,a.y-b.y);}
inline LL operator ^(const po &a,const po &b){return a.x*1ll*b.y-a.y*1ll*b.x;}
inline LL operator *(const po &a,const po &b){return a.x*1ll*b.x+a.y*1ll*b.y;}
inline po operator *(const po &a,const LL &b){return po(a.x*b,a.y*b);}
int n,Q,k;
po v[15]; 
po pos[N];int a[N];
po pp[N];int t[N];
inline bool cmpDELTA(const po &a,const po &b){return atan2(a.y,a.x)>atan2(b.y,b.x);}
//bitsum
LL sumbit[N];
int M;
inline void add(int x,int v){
	for(;x<=M;x+=(x&(-x)))sumbit[x]+=v;
}
inline LL ask(int x){
	LL ans=0;
	for(;x;x-=(x&(-x)))ans+=sumbit[x];
	return ans;
}
//bit
LL ans[N];
LL tmp[N];
int get(LL x){
	return upper_bound(tmp+1,tmp+1+M,x)-tmp-1;
}
struct opt{
	int ty;
	LL x;
	int l,r;
}ww[N*5];
int ts;
inline bool cmpww(const opt &a,const opt &b){
	if(a.x==b.x)return a.ty<b.ty;
	else return a.x<b.x;
}
int main(){
	scanf("%d%d%d",&k,&n,&Q);
	rep(i,1,k){
		scanf("%lld%lld",&v[i].x,&v[i].y);
		if(v[i].x<0)v[i]=po(0,0)-v[i];
		if(v[i].x==0&&v[i].y<0){
			v[i]=po(0,0)-v[i];
		}
	}
	sort(v+1,v+1+k,cmpDELTA);
	po sumPos=po(0,0);
	rep(i,1,k)sumPos=sumPos+v[i];

	rep(i,1,n){
		scanf("%lld%lld%d",&pos[i].x,&pos[i].y,&a[i]);
		tmp[++M]=pos[i].x;

	}

	sort(tmp+1,tmp+1+M);
	M=unique(tmp+1,tmp+1+M)-tmp-1;

	rep(i,1,Q){
		scanf("%lld%lld%d",&pp[i].x,&pp[i].y,&t[i]);
	}

	po now=po(0,0);
	bool fst=1;
	rep(i,1,k){
		memset(sumbit,0,sizeof sumbit);
		LL A=-v[i].y;
		LL B=v[i].x;
		ts=0;
		if(B!=0){
			rep(j,1,Q){
				po X=now*(2*t[j])+pp[j]-sumPos*t[j];
				po Y=X+v[i]*(2*t[j]);
				/*
				printf("_%lld %lld\n",v[i].x,v[i].y);
				printf("%lld %lld\n",pp[j].x,pp[j].y);
				printf("%lld %lld\n",X.x,X.y);
				printf("%lld %lld\n",Y.x,Y.y);
				printf("%d\n",t[j]);
				*/
				++ts;
				ww[ts].ty=j;
				ww[ts].x=X.x*A+X.y*B;
				ww[ts].l=get(X.x);
				ww[ts].r=get(Y.x);
				if(fst&&ww[ts].l&&X.x==tmp[ww[ts].l])--ww[ts].l;
			}
			rep(j,1,n){
				++ts;
				ww[ts].ty=0;
				ww[ts].x=pos[j].x*A+pos[j].y*B;
				ww[ts].l=get(pos[j].x);
				ww[ts].r=a[j];
			}
			sort(ww+1,ww+1+ts,cmpww);

			rep(j,1,ts){
				if(ww[j].ty){
					ans[ww[j].ty]+=ask(ww[j].r)-ask(ww[j].l);
				}
				else{
					add(ww[j].l,ww[j].r);
				}
			}
			fst=0;
		}
		//printf("ans:%lld\n",ans[1]);
		//end
		now=now+v[i];
	}
	now=po(0,0);
	fst=1;
	per(i,k,1){
		memset(sumbit,0,sizeof sumbit);
		LL A=-v[i].y;
		LL B=v[i].x;
		ts=0;
		if(B!=0){
			rep(j,1,Q){
				po X=(now)*(2*t[j])+pp[j]-sumPos*t[j];
				po Y=X+v[i]*(2*t[j]);
				/*
				printf("_%lld %lld\n",v[i].x,v[i].y);
				printf("%lld %lld\n",pp[j].x,pp[j].y);
				printf("%lld %lld\n",X.x,X.y);
				printf("%lld %lld\n",Y.x,Y.y);
				printf("%d\n",t[j]);
				*/
				++ts;
				ww[ts].ty=j;
				ww[ts].x=X.x*A+X.y*B-1;
				ww[ts].l=get(X.x);
				ww[ts].r=get(Y.x);
				if(fst&&ww[ts].l&&X.x==tmp[ww[ts].l])--ww[ts].l;
			}
			rep(j,1,n){
				++ts;
				ww[ts].ty=0;
				ww[ts].x=pos[j].x*A+pos[j].y*B;
				ww[ts].l=get(pos[j].x);
				ww[ts].r=a[j];
			}
			sort(ww+1,ww+1+ts,cmpww);

			rep(j,1,ts){
				if(ww[j].ty){
					ans[ww[j].ty]-=ask(ww[j].r)-ask(ww[j].l);
				}
				else{
					add(ww[j].l,ww[j].r);
				}
			}
			fst=0;
		}
		//end
		now=now+v[i];
		//printf("%lld\n",ans[1]);
	}
	if(v[k].x==0){
		memset(ans,0,sizeof ans);
		memset(sumbit,0,sizeof sumbit);
		ts=0;
		rep(i,1,Q){
			++ts;
			ww[ts].ty=i;
			ww[ts].x=pp[i].y+t[i]*sumPos.y;
			ww[ts].l=ww[ts].r=get(pp[i].x);
			if(tmp[ww[ts].l]!=pp[i].x)
				ww[ts].l=ww[ts].r=0;
		}
		rep(i,1,n){
			++ts;
			ww[ts].ty=0;
			ww[ts].x=pos[i].y;
			ww[ts].l=get(ww[ts].x);
			ww[ts].r=a[i];
		}
		sort(ww+1,ww+1+ts,cmpww);

		rep(j,1,ts){
			if(ww[j].ty){
				ans[ww[j].ty]+=ask(ww[j].r)-ask(ww[j].l);
			}
			else{
				add(ww[j].l,ww[j].r);
			}
		}

		memset(ans,0,sizeof ans);
		memset(sumbit,0,sizeof sumbit);
		ts=0;
		rep(i,1,Q){
			++ts;
			ww[ts].ty=i;
			ww[ts].x=pp[i].y-t[i]*sumPos.y-1;
			ww[ts].l=ww[ts].r=get(pp[i].x);
			if(tmp[ww[ts].l]!=pp[i].x)
				ww[ts].l=ww[ts].r=0;
		}
		rep(i,1,n){
			++ts;
			ww[ts].ty=0;
			ww[ts].x=pos[i].y;
			ww[ts].l=get(ww[ts].x);
			ww[ts].r=a[i];
		}
		sort(ww+1,ww+1+ts,cmpww);

		rep(j,1,ts){
			if(ww[j].ty){
				ans[ww[j].ty]-=ask(ww[j].r)-ask(ww[j].l);
			}
			else{
				add(ww[j].l,ww[j].r);
			}
		}
	}
	rep(i,1,Q)printf("%lld\n",ans[i]);
	return 0;
}