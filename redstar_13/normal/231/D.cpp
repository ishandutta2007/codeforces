#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

	



int main(){

	int x,y,z, xx, yy, zz,i,j,k;

	int a[6];

	cin>>xx>>yy>>zz>>x>>y>>z;

	

	for(i=1; i<=6; i++) cin>>a[i];

	int ans=0;

	if(xx<=x && xx>=0 && yy>=0 && yy<=y && zz>=0 && zz<=z) for( i=1; i<=6; i++) ans+=a[i];

	else {

		if(zz>z) ans+=a[4];

		if(zz==z && xx<=x && yy<=y && xx>=0 && yy>=0) ans+=a[4];

		

		if(zz<0) ans+=a[3];

		if(zz==0 && xx<=x && yy<=y && xx>=0 && yy>=0) ans+=a[3];

		

		if(xx>x) ans+=a[6];

		if(xx==x && zz<=z && yy<=y && zz>=0 && yy>=0) ans+=a[6];

		

		if(xx<0) ans+=a[5];

		if(xx==0 && zz<=z && yy<=y && zz>=0 && yy>=0) ans+=a[5];

		

		if(yy>y) ans+=a[2];

		if(yy==y && zz<=z && xx<=x && zz>=0 && xx>=0) ans+=a[2];

		

		if(yy<0) ans+=a[1];

		if(yy==0 && zz<=z && xx<=x && zz>=0 && xx>=0) ans+=a[1];

	}

	cout<<ans<<endl;

	return 0;

}