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
int de(string a){
	if(a=="rock") return 0;
	else if(a=="paper") return 1;
	else return 2;
}
int main()
{
	string a,b,c;int x,y,z;
	cin>>a>>b>>c;x=de(a);y=de(b);z=de(c);
	if((x+3-y)%3==1 && (x+3-z)%3==1) cout<<"F"<<endl;
	else if((y+3-x)%3==1 && (y+3-z)%3==1) cout<<"M"<<endl;
	else if((z+3-x)%3==1 && (z+3-y)%3==1) cout<<"S"<<endl;
	else cout<<"?"<<endl;
	return 0;
}