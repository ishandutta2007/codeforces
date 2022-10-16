#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int x[1000010],lala,temp;
long long a,b,c,d,e;
int main(){
ios_base::sync_with_stdio(0);
	cin>>a>>b>>c;
	x[1]=1;
	rep(i,b){
		cin>>d;
		x[d]=2;
	}
	if(x[1]==2){
		cout<<1<<endl;
		return 0;
	}
	rep(i,c){
		cin>>d>>e;
		lala=x[e], temp=x[d];
		if(lala==0 && temp==1){
			x[e]=1;
			x[d]=0;
		}else if(lala==1 && temp==0){
			x[e]=0;
			x[d]=1;
		}
		else if((temp==1 && lala==2)||(temp==2 && lala==1)){
			swap(x[d],x[e]); break;
		}
	}
	rep(i,a+5){
		if(x[i+1]==1){
		cout<<i+1<<endl;
		return 0;	
		}
	}
	cout<<e<<endl;
	return 0;
}