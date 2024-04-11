#include<bits/stdc++.h>
const int N=400005;
typedef long long ll;
using namespace std;
int n,m,x,sum,b[N],sloc,ss[N],tp1[N],tp2[N],t1,t2;
struct dat{
	int loc,typ,no;
}a[N];
ll ans,now,c[N*2];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	scanf("%d",&x),a[i]={x,1,i};
	for(int i=0;i<n;i++)
	scanf("%d",&x),a[i+n]={x,-1,i};
	n<<=1;
	sort(a,a+n,[](dat x,dat y){
		return x.loc<y.loc;
	});
	b[0]=sum=n;
	for(int i=0;i<n;i++){
		//cerr<<b[i]<<','<<a[i].typ<<','<<a[i].loc<<endl;
		if(a[i].typ<0)
		c[b[i]]-=2ll*a[i].loc,now+=a[i].loc;
		else c[b[i]+1]+=2ll*a[i].loc,now-=a[i].loc;
		b[i+1]=b[i]+a[i].typ;
	}
	for(int i=0;i<=n;i++)
	now+=c[i];
	//for(int i=0;i<=n*2;i++)
	//if(c[i])cerr<<i<<':'<<c[i]<<endl;
	ans=now;
	//cerr<<now<<"???\n";
	for(int i=0;i<n;i++){
		if(a[i].typ<0){
			now-=c[sum--];
			c[b[i]]-=2ll*m;
			now+=m;
		}
		else{
			now+=c[++sum];
			c[b[i]+1]+=2ll*m;
			now+=m;
		}
		//cerr<<now<<"..\n";
		if(ans>now)ans=now,sloc=i+1;
	}
	for(int i=sloc;i<n;i++)
	if(a[i].typ<0)tp2[t2++]=a[i].no;
	else tp1[t1++]=a[i].no;
	for(int i=0;i<sloc;i++)
	if(a[i].typ<0)tp2[t2++]=a[i].no;
	else tp1[t1++]=a[i].no;
	for(int i=0;i<t1;i++)ss[tp1[i]]=tp2[i];
	printf("%lld\n",ans);
	for(int i=0;i<t1;i++)
	printf("%d ",ss[i]+1);
}