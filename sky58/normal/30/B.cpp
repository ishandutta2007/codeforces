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
int d,m,y;
int mo[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool ch(int bd,int bm,int by){
	if(bm>12) return false;
	if(mo[bm-1]>=bd) return true;
	if(by%4==0 && bm==2 && bd==29) return true;return false;
}
bool ch2(int bd,int bm,int by){
	int x1=10000*y+100*m+d,x2=10000*by+100*bm+bd;
	if(x1-x2>=180000) return true;return false;
}
int main()
{
	int bd,bm,by;string a,b;
	cin>>a;cin>>b;
	d=(a[0]-'0')*10+(a[1]-'0');m=(a[3]-'0')*10+(a[4]-'0');y=(a[6]-'0')*10+(a[7]-'0');
	bd=(b[0]-'0')*10+(b[1]-'0');bm=(b[3]-'0')*10+(b[4]-'0');by=(b[6]-'0')*10+(b[7]-'0');
	if(ch(bd,bm,by) && ch2(bd,bm,by)){cout<<"YES"<<endl;return 0;}
	if(ch(bd,by,bm) && ch2(bd,by,bm)){cout<<"YES"<<endl;return 0;}
	if(ch(bm,bd,by) && ch2(bm,bd,by)){cout<<"YES"<<endl;return 0;}
	if(ch(bm,by,bd) && ch2(bm,by,bd)){cout<<"YES"<<endl;return 0;}
	if(ch(by,bm,bd) && ch2(by,bm,bd)){cout<<"YES"<<endl;return 0;}
	if(ch(by,bd,bm) && ch2(by,bd,bm)){cout<<"YES"<<endl;return 0;}
	cout<<"NO"<<endl;return 0;
}