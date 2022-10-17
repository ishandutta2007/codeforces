#include <cstdio>
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
typedef long long ll;
const int Maxn=100000;
const ll Inf=4e18;
int n;
struct Node{
	ll x,y,z;
}a[Maxn+5];
ll X,Y,Z;
bool check(ll x){
	ll maxn,max_x,max_y,max_z;
	maxn=max_x=max_y=max_z=Inf;
	ll minn,min_x,min_y,min_z;
	minn=min_x=min_y=min_z=-Inf;
	for(int i=1;i<=n;i++){
		maxn=min(maxn,a[i].x+a[i].y+a[i].z+x);
		max_x=min(max_x,-a[i].x+a[i].y+a[i].z+x);
		max_y=min(max_y,a[i].x-a[i].y+a[i].z+x);
		max_z=min(max_z,a[i].x+a[i].y-a[i].z+x);
		minn=max(minn,a[i].x+a[i].y+a[i].z-x);
		min_x=max(min_x,-a[i].x+a[i].y+a[i].z-x);
		min_y=max(min_y,a[i].x-a[i].y+a[i].z-x);
		min_z=max(min_z,a[i].x+a[i].y-a[i].z-x);
	}
	for(int i=0;i<2;i++){
		ll l=minn+((minn&1)^i),r=maxn-((maxn&1)^i);
		ll l_x=min_x+((min_x&1)^i),r_x=max_x-((max_x&1)^i);
		ll l_y=min_y+((min_y&1)^i),r_y=max_y-((max_y&1)^i);
		ll l_z=min_z+((min_z&1)^i),r_z=max_z-((max_z&1)^i);
		if(l>r||l_x>r_x||l_y>r_y||l_z>r_z){
			continue;
		}
		ll a=l_x,b=l_y,c=l_z;
		if(a+b+c>r){
			continue;
		}
		if(a+b+c<l){
			a=r_x<l-b-c?r_x:l-b-c;
		}
		if(a+b+c<l){
			b=r_y<l-a-c?r_y:l-a-c;
		}
		if(a+b+c<l){
			c=r_z<l-a-b?r_z:l-a-b;
		}
		if(a+b+c<l){
			continue;
		}
		X=(b+c)/2;
		Y=(a+c)/2;
		Z=(a+b)/2;
		return 1;
	}
	return 0;
}
int main(){
	int T;
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			read(a[i].x),read(a[i].y),read(a[i].z);
		}
		ll left=0,right=Inf;
		while(left<right){
			ll mid=(left>>1)+(right>>1);
			if((left&1)&&(right&1)){
				mid++;
			}
			if(check(mid)){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		check(left);
		printf("%lld %lld %lld\n",X,Y,Z);
	}
	return 0;
}