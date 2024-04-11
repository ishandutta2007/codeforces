#include<bits/stdc++.h>

using namespace std;

set<int> ans;

char str[1500];



int main(){

//	freopen("in.txt","r",stdin);

	int n,m,flag=0,s,g;



	cin>>n>>m;

	for(int i=0;i<n;i++) {

		scanf("%s",str);

		for(int j=0;j<m;j++) {

			if(str[j]=='G') g=j;	if(str[j]=='S') s=j;

		}

		if(s<g) flag=1;

		if(s>g)	ans.insert(s-g);

	}

	if(flag) puts("-1");

	else printf("%d\n",ans.size());

	return 0;

}