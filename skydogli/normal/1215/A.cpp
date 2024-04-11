#include<bits/stdc++.h>
using namespace std;
int a1,a2,k1,k2,n;
int main(){
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	if(k1<k2)swap(k1,k2),swap(a1,a2);
	if(n<=(k1-1)*a1+(k2-1)*a2){
		putchar('0');putchar(' ');
	}
	else printf("%d ",n-(k1-1)*a1-(k2-1)*a2);
	swap(k1,k2);swap(a1,a2);
//	cout<<k1<<" "<<k2<<" "<<a1<<" "<<a2<<endl;
	printf("%d",min(n/k1,a1)+(n/k1>a1?((n-k1*a1)/k2):0));
}