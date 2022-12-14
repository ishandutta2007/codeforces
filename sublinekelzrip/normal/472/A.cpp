#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
		cout<<n-4<<' '<<4<<endl;
	else
		if(n==13)
			cout<<4<<' '<<9<<endl;
		else
			if(n==15)
				cout<<6<<' '<<9<<endl;
			else
				if(n==17)
					cout<<8<<' '<<9<<endl;
				else
					cout<<n-15<<' '<<15<<endl;
}