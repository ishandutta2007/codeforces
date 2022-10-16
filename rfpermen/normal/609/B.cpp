#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int a,b,c,d,e,x[11];
int main(){
	cin>>a>>b; e=a, d=0;
	rep(i,a){
		cin>>c;
		if(c==1)x[1]++;
		else if(c==2)x[2]++;
		else if(c==3)x[3]++;
		else if(c==4)x[4]++;
		else if(c==5)x[5]++;
		else if(c==6)x[6]++;
		else if(c==7)x[7]++;
		else if(c==8)x[8]++;
		else if(c==9)x[9]++;
		else if(c==10)x[10]++;
	}
	rep(i,b){
		e=e-x[i+1];
		d=d+x[i+1]*e;
	}
	cout << d << endl;
	return 0;
}