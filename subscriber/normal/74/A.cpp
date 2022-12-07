#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,a,b,c,d,e,p1,p2;
pair<int,string> s[11111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s[i].second >> p1 >> p2 >> a >> b >> c >> d >> e;
		s[i].first=p1*100-p2*50+a+b+c+d+e;
	}
	sort(s,s+n);
	cout << s[n-1].second << endl;
	return 0;
}