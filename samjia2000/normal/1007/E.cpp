#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 205;
const LL INF = 1e15;

int n,t;
LL k;
LL a[N],b[N],c[N];
struct status{
	LL c,v;
	status(const LL c_=0,const LL	v_=0){c=min(INF,c_);v=min(INF,v_);}
	
	void update(){c=min(c,INF);v=min(v,INF);}
	
	friend bool operator <(status a,status b){return a.c!=b.c?a.c<b.c:a.v<b.v;}
}f0[N][N],f1[N][N],g0[N][N],g1[N][N],p[N];
//f for start from a
//g for start from b
//f0/g0 for to be cleaned
//f1/g1 is opposite to f0/g0
LL prea[N],preb[N];
LL limf[N],limg[N];

int main(){
	n=get();t=get();k=get();
	fo(i,1,n){a[i]=get();b[i]=get();c[i]=get();}
	bool can=1;
	fo(i,1,n)can&=(a[i]<=c[i]&&b[i]<=c[i]);
	if (!can)return printf("-1\n"),0;
	fo(i,1,n){
		prea[i]=prea[i-1]+a[i];
		preb[i]=preb[i-1]+b[i];
	}
	fo(r,1,t)fo(i,1,n)f0[r][i]=f1[r][i]=g0[r][i]=g1[r][i]=status(INF,INF);
	fo(i,1,n){
		fo(r,1,t)p[r]=status(INF,INF);
		fo(r,1,t){
			status v=f0[r][i-1];
			if (v.c<INF){
				LL sum=1ll*v.c*k-prea[i-1]-preb[i-1]*(r-1);
				sum=a[i]+b[i]*(r-1)-sum;
				if (a[i]+b[i]*(r-1)<=c[i]&&sum>=0)p[r]=status(v.c,sum);
			}
			fo(s,1,r-1)
			if (p[s].c<INF){
				status u=p[s];
				status v=g0[r-s][i-1];
				if (v.c<INF){
					LL sum=v.c*k-preb[i-1]*(r-s);
					sum=b[i]*(r-s)-sum;
					if (u.v+sum>=0){
						if (u.v%k+b[i]*(r-s)<=c[i]){
							LL need=(u.v+b[i]*(r-s)-c[i])/k;
							need=max(need,0ll);
							while(u.v-need*k+b[i]*(r-s)>c[i])need++;
							if (need*k<=u.v){
								u.v=u.v-need*k+sum;
								u.c=u.c+need+v.c;
								p[r]=min(p[r],u);
							}
						}
					}
				}
			}
		}
		//f0 : start from a/to be cleaned
		fo(r,1,t){
			status v=f0[r][i-1];
			if (v.c<INF&&a[i]+b[i]*(r-1)<=c[i]){
				LL sum=1ll*v.c*k-prea[i-1]-preb[i-1]*(r-1);
				sum=a[i]+b[i]*(r-1)-sum;
				if (sum>0){
					LL need=(sum-1)/k+1;
					v.c+=need;
					sum-=need*k;
				}
				f0[r][i]=v;
			}
			fo(s,1,r-1)
			if (p[s].c<INF){
				status u=p[s];
				status v=g0[r-s][i-1];
				if (v.c<INF){
					LL sum=v.c*k-preb[i-1]*(r-s);
					sum=b[i]*(r-s)-sum;
					if (u.v%k+b[i]*(r-s)<=c[i]){
						LL need=(u.v+b[i]*(r-s)-c[i])/k;
						need=max(need,0ll);
						while(u.v-need*k+b[i]*(r-s)>c[i])need++;
						u.c+=need;
						u.v-=need*k;
						u.c+=v.c;
						u.v+=sum;
						if (u.v>0){
							LL need=(u.v-1)/k+1;
							u.c+=need;
							u.v-=need*k;
						}
						f0[r][i]=min(f0[r][i],u);
					}
				}
			}
		}
		//f1 : start from a[i]/not to be cleaned
		fo(r,1,t){
			if (a[i]+b[i]*r<=c[i]){
				status v=f1[r][i-1];
				f1[r][i]=min(f1[r][i],v);
			}
			if (p[r].c<INF){
				status v=p[r];
				if (v.v+b[i]>c[i]){
					LL need=(v.v+b[i]-c[i]-1)/k+1;
					v.v-=need*k;
					v.c+=need;
				}
				if (v.v>=0)f1[r][i]=min(f1[r][i],v);
			}
			fo(s,1,r-1)
			if (p[s].c<INF){
				status u=p[s];
				status v=g1[r-s][i-1];
				if (v.c<INF){
					if (u.v%k+b[i]*(r-s+1)<=c[i]){
						LL need=(u.v+b[i]*(r-s+1)-c[i])/k;
						need=max(need,0ll);
						while(u.v-need*k+b[i]*(r-s+1)>c[i])need++;
						u.c+=need;
						u.v-=need*k;
						u.c+=v.c;
						f1[r][i]=min(f1[r][i],u);
					}
				}
			}
		}
		//g start from b
		fo(r,1,t)p[r]=status(INF,INF);
		fo(r,1,t){
			status v=g0[r][i-1];
			if (v.c<INF){
				LL sum=1ll*v.c*k-preb[i-1]-preb[i-1]*(r-1);
				if (b[i]*r<=c[i]&&sum<=b[i]*r)p[r]=status(v.c,b[i]*r-sum);
			}
			fo(s,1,r-1)
			if (p[s].c<INF){
				status v=g0[r-s][i-1];
				status u=p[s];
				if (v.c<INF){
					LL sum=v.c*k-preb[i-1]*(r-s);
					sum=b[i]*(r-s)-sum;
					if (u.v+sum>=0){
						if (u.v%k+b[i]*(r-s)<=c[i]){
							LL need=(u.v+b[i]*(r-s)-c[i])/k;
							need=max(need,0ll);
							while(u.v-need*k+b[i]*(r-s)>c[i])need++;
							if (need*k<=u.v){
								u.v=u.v-need*k+sum;
								u.c=u.c+need+v.c;
								p[r]=min(p[r],u);
							}
						}
					}
				}
			}
		}
		//g0 : start from b/to be cleaned
		fo(r,1,t){
			status v=g0[r][i-1];
			if (v.c<INF&&b[i]*r<=c[i]){
				LL sum=1ll*v.c*k-preb[i-1]*r;
				sum=b[i]*r-sum;
				if (sum>0){
					LL need=(sum-1)/k+1;
					v.c+=need;
					sum-=need*k;
				}
				g0[r][i]=v;
			}
			fo(s,1,r-1)
			if (p[s].c<INF){
				status u=p[s];
				status v=g0[r-s][i-1];
				if (v.c<INF){
					LL sum=v.c*k-preb[i-1]*(r-s);
					sum=b[i]*(r-s)-sum;
					if (u.v%k+b[i]*(r-s)<=c[i]){
						LL need=(u.v+b[i]*(r-s)-c[i])/k;
						need=max(need,0ll);
						while(u.v-need*k+b[i]*(r-s)>c[i])need++;
						u.c+=need;
						u.v-=need*k;
						u.c+=v.c;
						u.v+=sum;
						if (u.v>0){
							LL need=(u.v-1)/k+1;
							u.c+=need;
							u.v-=need*k;
						}
						g0[r][i]=min(g0[r][i],u);
					}
				}
			}
		}
		//g1 : start from b[i]/not to be cleaned
		fo(r,1,t){
			if (b[i]*(r+1)<=c[i]){
				status v=g1[r][i-1];
				g1[r][i]=min(g1[r][i],v);
			}
			if (p[r].c<INF){
				status v=p[r];
				if (v.v+b[i]>c[i]){
					LL need=(v.v+b[i]-c[i]-1)/k+1;
					v.v-=need*k;
					v.c+=need;
				}
				if (v.v>=0)g1[r][i]=min(g1[r][i],v);
			}
			fo(s,1,r-1)
			if (p[s].c<INF){
				status u=p[s];
				status v=g1[r-s][i-1];
				if (v.c<INF){
					if (u.v%k+b[i]*(r-s+1)<=c[i]){
						LL need=(u.v+b[i]*(r-s+1)-c[i])/k;
						need=max(need,0ll);
						while(u.v-need*k+b[i]*(r-s+1)>c[i])need++;
						u.c+=need;
						u.v-=need*k;
						u.c+=v.c;
						g1[r][i]=min(g1[r][i],u);
					}
				}
			}
		}
	}
	//prt();
	LL ans=f1[t][n].c;
	fo(r,1,t)p[r]=status(INF,INF);
	fo(r,1,t){
		p[r]=f0[r][n];
		fo(s,1,r-1){
			status v=p[s];
			if (v.c<INF){
				v.c=v.c+g0[r-s][n].c;
				v.update();
				p[r]=min(p[r],v);
			}
		}
		ans=min(ans,p[r].c+g1[t-r][n].c);
	}
	cout<<ans<<endl;
	return 0;
}