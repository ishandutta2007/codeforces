#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=100005;
char a[N][9];
int ty[N];
int n;
int e;
bool hav[N];
int m=0;
int q1[N];
int q2[N];
int ans;
int fr[N],to[N];
int get(int x){
	int len=strlen(a[x]+1);
	if(a[x][1]=='0')return 0;
	int w=0;
	rep(i,1,len){
		if(a[x][i]<='9'&&a[x][i]>='0'){
			w*=10;
			w+=(a[x][i]-'0');
		}
		else return 0;
	}
	if(w>n)w=0;
	return w;
}
void move(int a,int b){
	if(a<=n&&a>=1)hav[a]=0;
	if(b<=n&&b>=1)hav[b]=1;
	++ans;
	fr[ans]=a;to[ans]=b;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",a[i]+1);
		scanf("%d",&ty[i]);
		e+=ty[i];
	}
	int kg=0;
	rep(i,1,n){
		int w=get(i);
		if(w&&w<=n){
			if(w<=e&&ty[i]){
				hav[w]=1;
				++m;
			}
			if(w>e&&w<=n&&(ty[i]==0)){
				hav[w]=1;
				++m;
			}
			if(w<=e&&ty[i]==0){
				q1[++q1[0]]=i;
				hav[w]=1;
			}
			if(w>e&&w<=n&&ty[i]==1){
				q2[++q2[0]]=i;
				hav[w]=1;
			}
		}
		else{
			kg=i;
		}
	}
	if(m==n){printf("0\n");return 0;}
	if(!kg){
		assert(q1[0]==q2[0]);
		move(get(q1[1]),n+1);
		move(get(q2[1]),get(q1[1]));
		rep(i,2,q1[0]){
			move(get(q1[i]),get(q2[i-1]));
			move(get(q2[i]),get(q1[i]));
		}
		move(n+1,get(q2[q2[0]]));
	}
	else{
		//rep(i,1,n)printf("%d ",hav[i]);puts("");
		if((q1[0]>q2[0])||(q1[0]==q2[0]&&e<n-e)){
			tt:;
			kg=0;
			rep(i,e+1,n)if(!hav[i])kg=i;
			if(!kg)goto gg;
			//rep(i,e+1,n)printf("%d ",hav[i]);puts("");
			//printf("_%d\n",kg);
			per(i,q2[0],1){
				move(get(q1[q1[0]]),kg);
				move(get(q2[i]),get(q1[q1[0]]));
				hav[kg]=1;
				q1[0]--;
				kg=get(q2[i]);
			}
			if(q1[0]){
				move(get(q1[q1[0]--]),kg);
			}
			else hav[kg]=0;

			rep(i,e+1,n)if(!hav[i]){
				if(q1[0])move(get(q1[q1[0]--]),i);
			}
		}
		else{
			gg:;
			int kg=0;
			rep(i,1,e)if(!hav[i])kg=i;
			if(!kg)goto tt;
			per(i,q1[0],1){
				move(get(q2[q2[0]]),kg);
				move(get(q1[i]),get(q2[q2[0]]));
				hav[kg]=1;
				q2[0]--;
				kg=get(q1[i]);
			}
			if(q2[0]){
				move(get(q2[q2[0]--]),kg);
			}
			else hav[kg]=0;

			rep(i,1,e)if(!hav[i]){
				if(q2[0])move(get(q2[q2[0]--]),i);
			}
		}

		int t=e+1;

		//rep(i,1,n)printf("%d ",hav[i]);puts("");
		rep(i,1,n)if(!ty[i])if(!(get(i)&&get(i)<=n)){
			while(hav[t])++t;
			move(-i,t);
			hav[t]=1;
		}
		t=1;
		rep(i,1,n)if(ty[i])if(!(get(i)&&get(i)<=n)){
			while(hav[t])++t;
			move(-i,t);
			hav[t]=1;
		}
	}
	printf("%d\n",ans);
	rep(i,1,ans){
		printf("move ");
		if(fr[i]>0)printf("%d ",fr[i]);
		else printf("%s ",a[-fr[i]]+1);
		if(to[i]>0)printf("%d\n",to[i]);
		else printf("%s\n",a[-to[i]]+1);
	}
	return 0;
}