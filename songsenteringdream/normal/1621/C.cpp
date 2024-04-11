#include<iostream>
using namespace std;
const int o=1e4+10;
int T,n,p[o];
inline int query(int pos){
	cout<<"? "<<pos<<endl;cout.flush();
	int x;
	cin>>x;
	return x;
}
int main(){
	for(cin>>T;T--;cout.flush()){
		cin>>n;
		for(int i=1;i<=n;++i) p[i]=0;
		for(int i=1;i<=n;++i) if(!p[i])
			for(int j=query(i);!p[j];p[j]=query(i),j=p[j]);
		cout<<"!";
		for(int i=1;i<=n;++i) cout<<" "<<p[i];cout<<endl;
	}
	return 0;
}