#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

long i;
long ans,T0,T1,T2,X1,X2,Y1,Y2;
long long fz,fm;
long long f1,f2,f3,f4,f5,d;
inline long long gcd(long long x,long long y){
	register long long z;
	while(z=x%y) x=y,y=z;
	return y;
}

int main(){
	cin>>T1>>T2>>X1>>X2>>T0;
	if(T1==T2){cout<<X1<<' '<<X2<<endl;return 0;}
	if(T1==T0){cout<<X1<<" 0\n";return 0;}
	if(T2==T0){cout<<"0 "<<X2<<endl;return 0;}
	fz=10000000,fm=1;
	for(i=1;i<=X2;++i){
		f1=(long long)(T2-T0)*i/(T0-T1);
		if(X1<f1) f1=X1;
		f2=f1+i;
		f3=(long long)i*T2+f1*T1;
		d=gcd(f2,f3);
		f2/=d,f3/=d;
		if(f3==fz&&f2==fm) {if(Y1+Y2<i+f1) Y2=i,Y1=f1;}
		else if((long double)f3/f2<(long double)fz/fm) fz=f3,fm=f2,Y2=i,Y1=f1;
		}
	cout<<Y1<<' '<<Y2<<endl;
	cin>>T1;
	return 0;
}