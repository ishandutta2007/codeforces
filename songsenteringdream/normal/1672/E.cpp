#include<iostream>
using namespace std;
int n,w,ans;
inline int query(int val){
	cout<<"? "<<val<<endl;
	int res;
	cin>>res;
	return res;
}
int main(){
	cin>>n;
	for(int l=1,r=1e7,md;l<r;w=l) if(query(md=l+r>>1)==1) r=md;else l=md+1;
	ans=w;
	for(int i=2,j;i<=n;++i) if(j=query((w-1)/i)) ans=min(ans,(w-1)/i*j);
	cout<<"! "<<ans<<endl;
	return 0;
}