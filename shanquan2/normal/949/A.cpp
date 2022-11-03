#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> a[200005];
char s[200005];
int main(){
	scanf("%s",s);
	n=strlen(s);
	int t=0;
	for(int i=0;i<n;i++)if(s[i]=='0')t++;else t--;
	if(s<=0){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			if(m<t){
				a[m].push_back(i);
				m++;
			}
			else{
				k--;
				if(k<0){
					printf("-1\n");
					return 0;
				}
				a[k].push_back(i);
			}
		}else{
			if(k>=m){
				printf("-1\n");
				return 0;
			}
			a[k++].push_back(i);
		}
	}
	printf("%d\n",m);
	for(int i=0;i<m;i++){
		printf("%d ",a[i].size());
		for(int j=0;j<a[i].size();j++)printf("%d ",a[i][j]+1);printf("\n");
	}
	return 0;
}