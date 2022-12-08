#include<bits/stdc++.h>
using namespace std;

int n;
struct n3{int x,y,z;};
struct n4{int x,y,z,w;};
vector<n3> r3;
vector<n4> r4;
void up(int &k){k=(k-1)%n+1;}
void p3(int x,int y,int z){
	up(x);up(y);up(z);
	r3.push_back((n3){x,y,z});//printf("3 %d %d %d\n",x,y,z);
}
void p4(int x,int y,int z,int w){
	up(x);up(y);up(z);up(w);
	r4.push_back((n4){x,y,z,w});
}
void print(){
	printf("%d\n",r3.size()+r4.size());
	for(int i=0;i<r3.size();i++)
		printf("3 %d %d %d\n",r3[i].x,r3[i].y,r3[i].z);
	for(int i=0;i<r4.size();i++)
		printf("4 %d %d %d %d\n",r4[i].x,r4[i].y,r4[i].z,r4[i].w);
}
void make(int n){
	if(n==4){
		p3(1,2,3);
		p3(2,3,4);
		p3(3,4,1);
		p3(4,1,2);
		return;
	}
	for(int i=1;i+3<=n;i+=4){
		p4(i,i+2,i+1,i+3);
		p4(i,i+1,i+3,i+2);
		p4(i,i+1,i+2,i+3);
	}
	if(n%4==0){
		for(int i=1;i<=n/2;i++)
			for(int j=i+1;j<=n/2;j++){
				if(i+1==j&&i&1) continue;
				p4(i*2-1,j*2-1,i*2,j*2);
				p4(i*2-1,j*2-1,i*2,j*2);
			}
	}
	else{
		for(int i=1;i<=n/2;i++)
			for(int j=i+1;j<=n/2;j++){
				if(i+1==j&&(i&1)) continue;
				if(i==1&&j==n/2) p3(i*2-1,n-1,n),p3(i*2,n-1,n); else p4(i*2-1,j*2-1,i*2,j*2);
				p4(i*2-1,j*2-1,i*2,j*2);
			}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif 
	scanf("%d",&n);
	if(n%2==0){
		make(n);
		print();
	}
	else{
		if(n==5){
			puts("6\n3 5 4 2\n3 3 1 5\n4 4 5 2 3\n4 4 3 2 1\n3 4 2 1\n3 3 1 5");
			return 0;
		}
		make(n-3);
		p3(n,n-1,n-2);
		p3(n,n-1,n-2);
		//n-=3;
		//cerr<<n<<endl;
		for(int i=1;i<=(n-3)/2;i++){
			p4(i*2-1,n,i*2,n-1);
			p4(i*2-1,n,i*2,n-2);
			p4(i*2-1,n-1,i*2,n-2);
		}
		print();
	}
}