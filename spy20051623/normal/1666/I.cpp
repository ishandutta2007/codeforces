#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int qry(int x,int y){
	cout<<"SCAN "<<x<<" "<<y<<endl;
	int ans;cin>>ans;
	return ans;
}
int dig(int x,int y){
	cout<<"DIG "<<x<<" "<<y<<endl;
	int ans;cin>>ans;
	return ans;
}
void work(){
	cin>>n>>m;
	int A=qry(1,1);
	int B=qry(1,m);
	int sx=(A+4+B-2*m+2)/2;
	int sy=(A+4-B+2*m-2)/2;	
	int C=qry(sx>>1,sy>>1);//
	int D=qry(sx>>1,1);
	int step=(A-C)/2;
	int stepx=(A-D)/2;
	int stepy=step-stepx;
	int x1=1+stepx;
	int y1=1+stepy;
	int x2=sx-x1;
	int y2=sy-y1;
	int f=dig(x1,y1);
	if(f){
		dig(x2,y2);
	}
	else{
		dig(x1,y2);
		dig(x2,y1);
	}
}
int main(){
	int T;cin>>T;
	while(T--)work();	
}
/*

x1+x2+y1+y2=A+4
x1-1+x2-1+m-y1+m-y2=B
x1+x2-y1-y2=B-2m+2
*/