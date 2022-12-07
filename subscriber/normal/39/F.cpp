#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> an;
int n,m,k,ans=111111,d[111],x[111];

int main(){
	an.clear();
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=0;i<m;i++)cin >> d[i];
	for (int i=0;i<k;i++)cin >> x[i];
	for (int i=0;i<m;i++){
		int s=0;
		for (int j=0;j<k;j++)if (x[i]-d[i]<=n&&x[j]%d[i]==0)s++;
		if (s==ans)an.push_back(i+1);else if (s<ans){
			ans=s;
			an.clear();
			an.push_back(i+1);
		}
	}
	cout << an.size() << endl;
	for (int i=0;i<an.size()-1;i++)cout << an[i] << " ";
	cout << an[an.size()-1] << endl;
	return 0;
}