#include<bits/stdc++.h>



using namespace std;



int main(){

	int n,d,dd=0,a[100];

	cin>>n>>d;

	for(int i=0;i<n;i++)

		scanf("%d",a+i);

	sort(a,a+n);

	reverse(a,a+n);

	for(int i=0;i<n;i++){

		for(int j=i;j<n;j++){

			printf("%d ",i+1);

			for(int k=0;k<i;k++)	printf("%d ",a[k]);

			printf("%d\n",a[j]);

			dd++;

			if(dd==d) return 0;

		}

	}

}