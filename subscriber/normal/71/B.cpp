#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,k,t,s=0,ans[11111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k >> t;
	for (int i=0;i<n;i++){
		for (int j=0;j<k;j++){
			if ((s+1)/1./n/k<=t/100.){
				ans[i]++;
				s++;
			}
		}
	}
	for (int i=0;i<n-1;i++)cout << ans[i] << " ";
	cout << ans[n-1] << endl;
	return 0;
}