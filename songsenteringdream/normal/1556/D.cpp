#include<iostream>
#include<algorithm>
using namespace std;
const int o=1e6+10;
int n,k,d1,d2,d3,d4,d5,d6,a[o];
#define j (1<<i)
int main(){
	cin>>n>>k;
	cout<<"and 1 2"<<endl;cout.flush();cin>>d1;
	cout<<"or 1 2"<<endl;cout.flush();cin>>d2;
	cout<<"and 1 3"<<endl;cout.flush();cin>>d3;
	cout<<"or 1 3"<<endl;cout.flush();cin>>d4;
	cout<<"and 2 3"<<endl;cout.flush();cin>>d5;
	cout<<"or 2 3"<<endl;cout.flush();cin>>d6;
	for(int i=30;i+1;--i)
		if((d1&j)&&(d3&j)&&(d5&j)) a[1]|=j,a[2]|=j,a[3]|=j;
		else if((d2&j)&&(d4&j)&&!(d6&j)) a[1]|=j;
		else if((d2&j)&&!(d4&j)&&(d6&j)) a[2]|=j;
		else if(!(d2&j)&&(d4&j)&&(d6&j)) a[3]|=j;
		else if((d1&j)&&!(d3&j)&&!(d5&j)) a[1]|=j,a[2]|=j;
		else if(!(d1&j)&&(d3&j)&&!(d5&j)) a[1]|=j,a[3]|=j;
		else if(!(d1&j)&&!(d3&j)&&(d5&j)) a[2]|=j,a[3]|=j;
	for(int i=4;i<=n;++i)
		cout<<"and 1 "<<i<<endl,cout.flush(),cin>>d1,
		cout<<"or 1 "<<i<<endl,cout.flush(),cin>>d2,
		a[i]=a[1]^d1^d2;
	sort(a+1,a+1+n);
	cout<<"finish "<<a[k];cout.flush();
	return 0;
}