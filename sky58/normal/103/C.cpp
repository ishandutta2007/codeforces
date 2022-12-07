#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
lint n,k;int p;string out="";
void cal1(lint a){
	if(a>n-k) out+='X';else out+='.';
	return;
}
void cal2(lint a){
	if(a>2*n-2*k) out+='X';
	else{
		if(a%2==0) out+='X';
		else out+='.';
	}
	return;
}
void cal3(lint a){
	if(a<=n-2*k) out+='.';
	else{
		if(a%2==0) out+='X';else out+='.';
	}
	return;
}
void cal4(lint a){
	if(a>=n) out+='X';
	else if(a>n-2*k+1){
		if(a%2==0) out+='X';else out+='.';
	}
	else out+='.';
	return;
}
int main()
{
	cin>>n>>k;cin>>p;lint a;int i;
	for(i=0;i<p;i++){
		cin>>a;
		if(k<2) cal1(a);
		else if(k*2>=n) cal2(a);
		else{
			if(n%2==0) cal3(a);else cal4(a);
		}
	}
	cout<<out<<endl;
	return 0;
}