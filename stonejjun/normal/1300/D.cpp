#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct poi{
	ll x,y;
};

ll ccw(poi a,poi m,poi b)
{
    ll t=(a.x-m.x)*(b.y-m.y)-(a.y-m.y)*(b.x-m.x);
    return (t<0)-(t>0);
}

ll cccw(poi a,poi b,poi c,poi d){
	d.x-=(c.x-b.x);
	d.y-=(c.y-b.y);
	//printf("%lld %lld %lld %lld %lld %lld %lld\n",a.x,a.y,b.x,b.y,d.x,d.y,ccw(a,b,d));
	return ccw(a,b,d);
}

ll dist(poi a,poi b)
{
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

poi arr[1010101];

bool sf(poi a,poi b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

bool sf2(poi a,poi b){
	return (ccw(arr[1],a,b)>0||(ccw(arr[1],a,b)==0&&dist(arr[1],a)<dist(arr[1],b)));
}

poi ch[1010101];
ll far[1010101];


int main(){
		ll i,j,k,l,m,n;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
			scanf("%lld %lld",&arr[i].x,&arr[i].y);
		sort(arr+1,arr+1+n,sf);
		sort(arr+2,arr+1+n,sf2);
		arr[n+1]=arr[1];
		m=n/2;
		if(n==0) {
			printf("NO");
			return 0;
		}
		ll chk=1;
		//for(i=1;i<=n+1;i++)
		for(i=1;i<=m;i++){
			if(arr[i+1].x-arr[i].x!=arr[i+m].x-arr[i+m+1].x||arr[i+1].y-arr[i].y!=arr[i+m].y-arr[i+m+1].y){
				chk=0;
				break;
			}
		}
		if(chk) printf("YES");
		else printf("NO");
	
	
}