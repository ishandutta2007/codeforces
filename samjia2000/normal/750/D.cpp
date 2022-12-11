#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if(ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int L = 5010;

bool f[L][L];
int v[L][L],ans,v_[L][L];
int n,k;
int mi[10];
int fx[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int main(){
	n=get();
	int x=L/2,y=L/2;
	mi[0]=1;fo(i,1,8)mi[i]=mi[i-1]*2;
	int u=x,d=x,l=y,r=y;
	v[x][y]=mi[0];
	f[x][y]=1;
	ans=1;
	fo(i,1,n){
		int t=get();
		if (i==1)t--;
		int  u_=u,d_=d,l_=l,r_=r;
		fo(x0,u,d)
			fo(y0,l,r)
				fo(w,0,7)
				if ((v[x0][y0]&mi[w])>0){
					int x_=x0,y_=y0;
					fo(s,1,t){
						x_+=fx[w][0];
						y_+=fx[w][1];
						if (!f[x_][y_]){
							f[x_][y_]=1;
							ans++;
							u_=min(u_,x_);
							d_=max(d_,x_);
							l_=min(l_,y_);
							r_=max(r_,y_);
						}
					}
					v_[x_][y_]|=mi[(w+7)%8]|mi[(w+1)%8];
				}
		u=u_;d=d_;l=l_;r=r_;
		fo(x0,u,d)
			fo(y0,l,r){
				v[x0][y0]=v_[x0][y0];
				v_[x0][y0]=0;
			}
	}
	printf("%d\n",ans);
	return 0;
}