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
string a[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
int main()
{
	int n;cin>>n;n--;
	while(n>4){
		n-=5;n/=2;
	}
	cout<<a[n]<<endl;
	return 0;
}