#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
bool prima[500001];
int a,b,c,z;
int main(){
	int X=500000;
	memset(prima,true,sizeof prima);
	prima[0]=false; prima[1]=false;
	for( int i=2;i*i<= X;i++){
		if (prima[i]) {
			for( int j=i*i; j<=X; j += i) {
				prima[j]= false;
			}
		}
	}
	cin>>a>>b;
	int x[a][b],y[a][b];
	rep(i,a){
		rep(j,b){
			cin>>x[i][j];
			c=0;
			z=x[i][j];
			while(!prima[z]){
				z++, c++;
			}
			y[i][j]=c;
		}
	}
	z=99999;
	rep(i,a){
		c=0;
		rep(j,b){
			c+=y[i][j];
		}
		if(c<z)z=c;
	}
	rep(j,b){
		c=0;
		rep(i,a){
			c+=y[i][j];
		}
		if(c<z)z=c;
	}
	cout<<z<<endl;
	return 0;
}