#include<bits/stdc++.h>



using namespace std;



int n, m, d, p, t, i, month[]={31,28,31,30,31,30,31,31,30,31,30,31};

int num[600], date, ans;



int main(){

	

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

	

	scanf("%d",&n);

	while(n--){

		scanf("%d%d%d%d",&m,&d,&p,&t);

		date=100+d;

		for(i=0;i<m-1;i++) date+=month[i];

		for(i=date-t;i<date;i++) num[i]+=p;

	}

	

	for(i=0;i<590;i++) ans=max(num[i],ans);

	printf("%d\n",ans);

	

	return 0;

}