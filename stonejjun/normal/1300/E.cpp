#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
struct poi{
	ll l,r,sum,siz;
};
 
poi arr[1010101];
ll par[1010101];
 
ll uf(ll a){
	if(a==par[a]) return a;
	return par[a]=uf(par[a]);
}
 
void mergee(ll a,ll b){
	a=uf(a);
	b=uf(b);
	swap(a,b);
	par[a]=b;
	arr[b].siz+=arr[a].siz;
	arr[b].sum+=arr[a].sum;
	arr[b].l=min(arr[b].l,arr[a].l);
	arr[b].r=max(arr[b].r,arr[a].r);
	
}
 
bool mg(poi a,poi b){
	return a.sum*b.siz>b.sum*a.siz;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll i,j,k,m,n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>arr[i].sum;
		arr[i].l=i;
		arr[i].r=i;
		arr[i].siz=1;
		par[i]=i;
	}
	ll fl=1;
	while(fl<=n){
		ll rfl=fl;
		ll lfl=arr[uf(fl-1)].l;
		while(mg(arr[uf(fl)],arr[rfl+1])&&rfl<n){
			rfl++;
			mergee(uf(fl),rfl);
			rfl=arr[uf(rfl)].r;
		}
		while(lfl>0&&mg(arr[uf(lfl)],arr[uf(fl)])){
			mergee(lfl,fl);
			lfl=arr[uf(lfl-1)].l;
		}
		//cout<<lfl<<' '<<fl<<' '<<rfl<<'\n';
		fl=rfl+1;
	}
	//for(i=1;i<=n;i++){
	//	printf("%lld %lld %lld\n",i,uf(i),arr[i].r);
	//}
	fl=1;
	while(fl<=n){
		ll rfl=arr[fl].r;
		long double ans=(long double)arr[fl].sum/arr[fl].siz;
		for(i=fl;i<=rfl;i++){
			printf("%.12f\n",(double)ans);
		}
		fl=rfl+1;
	}
	
}