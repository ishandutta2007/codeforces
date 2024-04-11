#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,f[111111],a[111111],kk;
vector<int> c[111111],q[111111];
                          
int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	f[1]=0;
	for (int i=1;i<=n;i++){
		q[i].push_back(i);
		int s=i,x=0;
		for (int j=1;;j++){
			q[i].push_back(q[i][j-1]+1);
			s+=q[i][j];
			if (s>n)break;
			c[s].push_back(i);
			
		}
	}
	for (int i=2;i<=n;i++){
		kk=0;
		for (int j=0;j<c[i].size();j++){
			int s=0,x=0;
			for (int k=0;s<i;k++){
				x^=f[q[c[i][j]][k]];
				s+=q[c[i][j]][k];
			}
			a[kk++]=x;
		}
		a[kk++]=999999999;
		sort(a,a+kk);
		if (a[0])f[i]=0;else{
			for (int j=0;j<kk-1;j++)if (a[j]+1<a[j+1]){
				f[i]=a[j]+1;
				break;
			}
		}
	}
	if (!f[n])puts("-1");else{
		for (int j=c[n].size()-1;j>=0;j--){
			int s=0,x=0,g=0;
			for (int k=0;s<n;k++){
				x^=f[q[c[n][j]][k]];
				s+=q[c[n][j]][k];
				g++;
			}
			if (!x){
				cout << g << endl;
				return 0;
			}
		}
	}
	return 0;
}