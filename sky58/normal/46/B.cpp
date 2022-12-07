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
int ha[10];
string si[5]={"S","M","L","XL","XXL"};
int de(string a){
	for(int i=0;i<5;i++){if(si[i]==a) return i;}
}
int main()
{
	int i,j,n;string s;
	for(i=0;i<5;i++) cin>>ha[i];cin>>n;
	for(i=0;i<n;i++){
		cin>>s;int t=de(s),f=1;
		for(j=0;j<5 && f>0;j++){
			int x=t+j,y=t-j;
			if(x<5) if(ha[x]>0){ha[x]--;cout<<si[x]<<endl;f=0;continue;}
			if(y>=0) if(ha[y]>0){ha[y]--;cout<<si[y]<<endl;f=0;continue;}
		}
	}
	return 0;
}