#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define f first
#define s second
#define ll long long
using namespace std;
ll n,m,le,ri,mid,mini,xmini,x[100010],y[100010],len1,len2,tmp;
int main(){
	cin>>n>>m;
	rep(i,n)scanf("%lld",&x[i]);
	rep(i,m)scanf("%lld",&y[i]);
	rep(i,n){
		tmp=x[i];
		
		le=1, ri=m, len1=0;
		while(le<ri && len1==0){
			mid=(le+ri)/2;
			if(y[mid]<tmp)le=mid+1;
			else if(y[mid]>tmp)ri=mid;
			else len1=mid;
		}
		if(tmp>y[m])len1=1000000000000;
		else if(len1==0)len1=abs(y[ri]-tmp);
		else len1=abs(y[len1]-tmp);
		
		le=1, ri=m, len2=0;
		while(le<=ri){
			mid=(le+ri)/2;
			if(y[mid]>tmp)ri=mid-1;
			else {
				len2=mid;
				le=mid+1;
			}
		}
		if(tmp<y[1])len2=1000000000000;
		else len2=abs(tmp-y[len2]);
		
		if(len1<len2)mini=len1;
		else mini=len2;
		//cout<<len2<<" "<<len1<<endl;
		if(xmini<mini)xmini=mini;
	}
	cout<<xmini<<endl;
	return 0;
}