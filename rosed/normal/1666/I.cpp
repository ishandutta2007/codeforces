#include<bits/stdc++.h>
using namespace std;
signed main(){
	int T; cin>>T;
	while(T--){
		int tmp;
		int n,m; cin>>n>>m;
		cout<<"SCAN 1 1"<<endl;
		int a; cin>>a; a+=4;
		cout<<"SCAN "<<n<<" 1"<<endl;
		int b; cin>>b; b+=2;
		int d=(a+b-2*n)/2;//y1+y2
		int c=a-d;//x1+x2
		cout<<"SCAN "<<(c/2)<<" "<<(d/2)<<endl;
		int aa,bb,cc; cin>>tmp;
		aa=(tmp+c+d)/2;//x1+y1
		bb=a-aa;//x2+y2
		cout<<"SCAN "<<1<<' '<<(d/2)<<endl;
		cin>>cc; cc+=2;
		int x1,x2,y1,y2;
		y1=(cc-c+d)/2; y2=d-y1;
		x1=aa-y1; x2=c-x1;
		cout<<"DIG "<<x1<<' '<<y1<<endl;
		cin>>tmp;
		if(tmp) {
			cout<<"DIG "<<x2<<' '<<y2<<endl;
			cin>>tmp;
			assert(tmp==1);
		} else {
			cout<<"DIG "<<x1<<' '<<y2<<endl;
			cin>>tmp;
			assert(tmp==1);
			cout<<"DIG "<<x2<<' '<<y1<<endl;
			cin>>tmp;
			assert(tmp==1);
		}
	}
	return 0;
}