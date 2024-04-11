#include<bits/stdc++.h>
using namespace std;
const int NN = 110;
int m,s,n;
char str[NN];

int main () {
	cin>>m>>s;
	if(s>m*9 or (s==0 and m>1)) puts("-1 -1"), exit(0);
	
	//min
	memset(str,'0',sizeof(str));
	if(s) n=max(s-9*(m-1),1); 
	str[0]=n+'0';
	n=s-n;
	for(int i=m-1;n>0;i--) str[i]=min(9,n)+'0',n-=9; 
	str[m]=0; cout<<str<<' ';
	
	//max
	memset(str,'0',sizeof(str));
	for(int i=0,n=s;n>0;i++) str[i]=min(9,n)+'0',n-=9;
	str[m]=0; cout<<str<<endl;
}