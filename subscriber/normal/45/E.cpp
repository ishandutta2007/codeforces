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

int n,ans[1111],f[1111],aa[111],bb[111];
string a[111],b[111];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)cin >> b[i];
	for (int i=0;i<n;i++)aa[a[i][0]-'A']++;
	for (int i=0;i<n;i++)bb[b[i][0]-'A']++;
	sort(a,a+n);
	sort(b,b+n);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)if (f[j]==0)if(a[i][0]==b[j][0]||bb[b[j][0]-'A']>aa[b[j][0]-'A']&&bb[a[i][0]-'A']<aa[a[i][0]-'A']){
			aa[a[i][0]-'A']--;
			bb[b[j][0]-'A']--;
			f[j]=1;
			ans[i]=j+1;
			break;
		}
	}
	for (int i=0;i<n-1;i++){
		cout << a[i] << " " << b[ans[i]-1] << ", ";
	}
	cout << a[n-1] << " " << b[ans[n-1]-1] << endl;
	return 0;
}