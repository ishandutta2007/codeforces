#include<iostream>
#include<algorithm>
using namespace std;
const int o=10000;
inline int query(int p1,int p2){
	int res;
	cout<<"? "<<p1<<" "<<p2<<endl;cout.flush();
	cin>>res;
	return res;
}
int n,a[o],p[o],A,B,x,y;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) a[i]=i;
	random_shuffle(a+1,a+n+1);
	x=query(A=a[1],B=a[2]);
	for(int i=3;i<=n;++i)
		if((y=query(A,a[i]))<x) B=a[i],x=y;
		else if(x==y) A=B,B=a[i],x=query(A,B);
	for(int i=114514,j,k;1;i=i*233ll%998244353)
		if(a[i%n+1]==A||a[i%n+1]==B);else
			if((j=query(a[i%n+1],A))<(k=query(a[i%n+1],B))) break;
			else if(j>k){A=B;break;}
	for(int i=1;i<=n;++i) if(i^A) p[i]=query(i,A);
	cout<<"!";
	for(int i=1;i<=n;cout<<" "<<p[i++]);
	cout.flush();
	return 0;
}