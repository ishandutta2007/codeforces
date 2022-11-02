// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n,k;
	string s,t;
	pair<int,string> ans(514514514,"shik");
	cin>>n>>k>>s;
	for ( int i=0; i<10; i++ ) {
		t=s;
		int cnt=count(s.begin(),s.end(),i+'0'),now=0;
		for ( int d=1; d<10; d++ ) {
			if ( i+d<10 )
				for ( int j=0; j<(int)t.size() && cnt<k; j++ )
					if ( t[j]==i+d+'0' ) {
						cnt++;
						now+=d;
						t[j]=i+'0';
					}
			if ( i-d>=0 )
				for ( int j=(int)t.size()-1; j>=0 && cnt<k; j-- )
					if ( t[j]==i-d+'0' ) {
						cnt++;
						now+=d;
						t[j]=i+'0';
					}
		}
		ans=min(ans,make_pair(now,t));
	}
	cout<<ans.first<<endl<<ans.second<<endl;
	return 0;
}