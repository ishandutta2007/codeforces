#include<bits/stdc++.h>

using namespace std;

vector<int> ans[150];

char str[15];



int main(){

	

//	freopen("in.txt","r",stdin);

	int n,flag,m,mm;

	cin>>n;

	for(int i=0;i<n;i++){

		scanf("%s",str);

		for(int a=1;a<=12;a++){

			if(12%a!=0) continue;

			mm=0;

			for(int k=0;k<12/a;k++){

				m=0;

				for(int j=0;j<a;j++)

				if(str[k+12/a*j]=='X') m++;

				mm=max(mm,m);

			}

			if(mm==a) ans[i].push_back(a);

		}

	}

	for(int i=0;i<n;i++) {

		int s=ans[i].size();

		printf("%d ",s);

		for(int j=0;j<s;j++) printf("%dx%d ",ans[i][j],12/ans[i][j]);

		printf("\n");

	}



	return 0;

}