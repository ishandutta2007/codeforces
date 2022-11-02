#include<bits/stdc++.h>



using namespace std;

int a[150];



int main(){

//	freopen("in.txt","r",stdin);

	int n,m,num,l;

	cin>>n;

	for(int i=1;i<=n;i++) scanf("%d",a+i);

	

	cin>>m;

	for(int i=0;i<m;i++){

		scanf("%d%d",&l,&num);

		if(l==1) {a[2]+=a[1]-num; a[1]=0;continue; }

		if(l==n) {a[n-1]+=num-1; a[n]=0;continue;}

		a[l-1]+=num-1;

		a[l+1]+=a[l]-num;

		a[l]=0;

	}

	

	for(int i=1;i<=n;i++)

	printf("%d\n",a[i]);



	return 0;

}