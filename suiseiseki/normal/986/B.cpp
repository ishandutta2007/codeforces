#include <cstdio>
#define Maxn 1000000
int a[Maxn+5];
int ans;
int d[Maxn+5];
void merge_sort(int left,int right){
	if(left>=right){
		return;
	}
	int mid=(left+right)>>1;
	merge_sort(left,mid);
	merge_sort(mid+1,right);
	int i=left,j=mid+1;
	int len=left-1;
	while(i<=mid&&j<=right){
		if(a[i]<a[j]){
			d[++len]=a[i];
			i++;
		}
		else{
			d[++len]=a[j];
			ans+=mid-i+1;
			j++;
		}
	}
	while(i<=mid){
		d[++len]=a[i++];
	}
	while(j<=right){
		d[++len]=a[j++];
	}
	for(int i=left;i<=right;i++){
		a[i]=d[i];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	merge_sort(1,n);
	if((ans&1)==(n&1)){
		puts("Petr");
	}
	else{
		puts("Um_nik");
	}
	return 0;
}