#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)

int main(){
	vector<int> a(4);
	forn(i,4)
		cin>>a[i];
	sort(a.begin(),a.end());
	bool t=0,s=0;
	forn(i,4){
		vector<int> b;
		forn(j,4)
			if(i!=j)
				b.push_back(a[j]);
		if(b[2]<b[0]+b[1])
			t=1;
		if(b[2]==b[0]+b[1])
			s=1;
	}
	if(t)
		cout<<"TRIANGLE";
	else if(s)
		cout<<"SEGMENT";
	else
		cout<<"IMPOSSIBLE";
	return 0;
}