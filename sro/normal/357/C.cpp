#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int killed[300005];

int main(){
	set<int> shit;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		shit.insert(i);
	}
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		set<int>::iterator itl=shit.lower_bound(a),itr=shit.upper_bound(b);
		for(set<int>::iterator it=itl;it!=itr;it++){
			if(*it!=c){
				killed[*it]=c;
			}
		}
		shit.erase(itl,itr);
		shit.insert(c);
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",killed[i],i==n?'\n':' ');
	}
	return 0;
}