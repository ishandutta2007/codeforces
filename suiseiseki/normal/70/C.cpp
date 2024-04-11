#include <cstdio>
#include <map>
#include <cstdlib>
#include <iostream>
using namespace std;
int mx,mn,w,x,y,ansx,ansy,co;
map<double,int> m1;
map<double,int> m2;
int rev(int k){
	int p=0;
	while(k>0){
		p=p*10+(k%10);
		k/=10;
	}
	return p;
}
int main (){
	double q;
	cin>>mx;
	cin>>mn;
	cin>>w;
	for(int i=1;i<=mx;i++) {
		q=(double)(i*1.0/rev(i));
		m1[q]++;
	}
	x=mx;
	y=0;
	co=0;
	while(y<=mn&&x>=1){
		if(co<w&&y<mn){
			y++;
			q=(double)((rev(y)*1.0)/y);
			co+=m1[q];
			m2[q]++;
		}
		else if(co>=w){
			if(ansx*ansy>x*y||ansx==0){
				ansx=x;
				ansy=y;
			}
			q=(double)((x*1.0)/rev(x));
			co-=m2[q];
			m1[q]--;
			x--;
		}
		else{
			y=mn+1;
		}
	}
	if(ansx==0){
		puts("-1");
	}
	else{
		cout<<ansx<<" "<<ansy<<endl;
	}
	return 0;
}