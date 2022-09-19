#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define last(a) a[a.size()-1]

int a[200000];
deque<pair<int,int> > mx,mn;
int m;
vector<pair<int,int> > ans;

int main(){
	int n,k;
	cin>>n>>k;
	m=-1;
	int j=0;
	forn(i,n){
		cin>>a[i];
		while(mn.size() && a[i]<=last(mn).first)
			mn.pop_back();
		mn.push_back(make_pair(a[i],i));
		while(mx.size() && a[i]>=last(mx).first)
			mx.pop_back();
		mx.push_back(make_pair(a[i],i));
		while(mx[0].first-mn[0].first>k){
			if(mn[0].second==j)
				mn.pop_front();
			if(mx[0].second==j)
				mx.pop_front();
			j++;
		}
		if(i-j>m){
			ans.resize(0);
			m=i-j;
		}
		if(i-j==m)
			ans.push_back(make_pair(j,i));
	}
	cout<<m+1<<' '<<ans.size();
	forn(i,ans.size())
		cout<<endl<<ans[i].first+1<<' '<<ans[i].second+1;
	return 0;
}