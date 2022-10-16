#include <bits/stdc++.h>
using namespace std;
int dig(int r,int c){
	cout << "DIG " << r << " " << c << endl;
	int ret;
	cin >> ret;
	return ret;	
}
int scan(int r,int c){
	cout << "SCAN " << r << " " << c << endl;
	int ret;
	cin >> ret;
	return ret;	
}
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (;T--;){
		int n,m;
		cin >> n >> m;
		int tmp1=scan(1,1);
		int tmp2=scan(1,m);
		int R=(tmp1+tmp2)/2-(m-1)+2;
		int C=tmp1-(R-2)+2;
		int tmp3=scan(R/2,1);
		int tmp4=scan(1,C/2);
		int r1=((tmp1+2)-tmp3)/2;
		int c1=((tmp1+2)-tmp4)/2;
		int r2=R-r1;
		int c2=C-c1;
		int res=dig(r1,c1);
		
		if (res) dig(r2,c2);
		else dig(r1,c2),dig(r2,c1);
	}
	return 0;
}