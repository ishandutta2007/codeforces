#include<bits/stdc++.h>
const int N=5003;
using namespace std;
int n,t,L,R,X;
long long now,ans;
struct pt{
	int x,y;
}a[N],b[N];
inline long long mul(pt u,pt v){
	return 1ll*u.x*v.y-1ll*v.x*u.y;
}
bool cmp(pt u,pt v){
	if(u.x>=0&&v.x<0)return 1;
	if(u.x<0&&v.x>=0)return 0;
	return mul(u,v)<0;
}
inline void sol(){
	sort(b,b+t,cmp);
	int i,j,k;
	for(i=0;i<t;i++)b[i+t]=b[i];
	now=0;
	for(j=1,k=1;j<t&&mul(b[i],b[j])<0;j++);
	for(int l=j;l<=t;l++){
		for(;k<j&&mul(b[l],b[k])<0;k++)
		now+=l-j;
	}
	ans+=now;
//	cout<<"prec ("<<j<<','<<k<<"):"<<now<<endl;
	for(i=1;i<t;i++,j=k){
		for(k=j;k<i+t&&mul(b[i],b[k])<0;k++);
		L=k-j,R=i+t-k,X=j-i;
		now+=L*(R-X);
	//	cout<<"kn "<<L<<','<<R<<','<<X<<endl;
	//	cout<<"at ("<<i<<','<<j<<','<<k<<"):"<<now<<endl;
		ans+=now;
	}
//	cout<<"fin "<<ans<<endl;
	t=0;
}
int main(){
//	freopen("dat.txt","r",stdin);
//	freopen("me.txt","w",stdout);
	scanf("%d",&n);
	if(n<=4)return puts("0"),0;
	for(int i=0;i<n;i++)
	scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		if(j^i)b[t++]={a[j].x-a[i].x,a[j].y-a[i].y};
		//cout<<"Sol ("<<a[i].x<<','<<a[i].y<<")\n";
		sol();
	}
	printf("%lld",ans*(n-4)/6);
}