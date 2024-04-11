#include<iostream>
using namespace std;
const int o=1<<13;
int n,ppc[o],a[o],b[o],v[o];long long ans[o],res;
int main(){
	cin>>n;
	for(int i=1;i<o;++i) ppc[i]=ppc[i>>1]+(i&1);
	for(int i=1,j=0;i<o;++i) if(ppc[i]==6) a[b[i]=++j]=i;
	for(int i=0,c=0;i<13;++i,res=c=0){
		for(int j=1;j<o;++j) if((j&(1<<i))&&b[j]&&b[j]<=n) v[++c]=b[j];
		if(c){cout<<"? "<<c;for(int j=1;j<=c;++j) cout<<" "<<v[j];cout<<endl;cout.flush();cin>>res;}
		ans[i]=res;
	}
	cout<<"!";
	for(int i=1;i<=n;cout<<" "<<res,res=0,++i) for(int j=0;j<13;++j) if(!(a[i]&(1<<j))) res|=ans[j];
	cout.flush();
	return 0;
}