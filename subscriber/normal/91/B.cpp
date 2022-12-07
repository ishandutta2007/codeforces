#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,a[111111],e[111111],st=0,l,r,c,d[111111],ans[111111],k=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=n-1;i>=0;i--){
		if (st){
			l=0;
			r=st-1;
			while (l<r){
				c=(l+r)>>1;
				if (e[c]>=a[i])l=c+1;else r=c;
			}
			if (e[l]>=a[i])ans[k++]=-1;else ans[k++]=d[l]-i-1;
		}else ans[k++]=-1;
		if (st==0||a[i]<e[st-1]){
			e[st]=a[i];
			d[st++]=i;
		}
	}
	for (int i=k-1;i;i--)printf("%d ",ans[i]);
	cout << ans[0] << endl;
	return 0;
}