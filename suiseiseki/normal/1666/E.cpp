#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int l,n;
int a[Maxn+5];
int mn_l[Maxn+5];
int mn_len,mx_len;
bool check_min(int len){
	int lst=0;
	for(int i=1;i<=n;i++){
		if(lst>a[i]){
			return 0;
		}
		if(a[i]-lst>len){
			lst=a[i];
		}
		else{
			lst+=len;
		}
	}
	if(lst>l){
		return 0;
	}
	return 1;
}
bool check_max(int len){
	int lst=0;
	for(int i=1;i<=n;i++){
		if(a[i]-lst>len){
			return 0;
		}
		lst+=len;
		lst=std::min(lst,mn_l[i+1]);
	}
	return lst==l;
}
int main(){
	scanf("%d%d",&l,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int left=0,right=l;
	while(left<right){
		int mid=(left+right+1)/2;
		if(check_min(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	mn_len=left;
	int lst=l;
	for(int i=n;i>0;i--){
		if(lst-a[i]>mn_len){
			lst=a[i];
			mn_l[i]=a[i];
		}
		else{
			mn_l[i]=lst-mn_len;
			lst-=mn_len;
		}
	}
	mn_l[n+1]=l;
	left=0,right=l;
	while(left<right){
		int mid=(left+right)/2;
		if(check_max(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	mx_len=left;
	lst=0;
	for(int i=1;i<=n;i++){
		printf("%d ",lst);
		lst=std::min(lst+mx_len,mn_l[i+1]);
		printf("%d\n",lst);
	}
	return 0;
}