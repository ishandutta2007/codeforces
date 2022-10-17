#include <cstdio>
char a[1000005];
char b[1000005];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int ans=0;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]&&b[i]!=b[i+1]&&a[i]==b[i+1]&&a[i+1]==b[i]){
			ans++;
			a[i]=b[i];
			a[i+1]=b[i+1];
			i++;
		}
		else if(a[i]!=b[i]){
			ans++;
			a[i]=b[i];
		}
	}
	if(a[n]!=b[n]){
		a[n]=b[n];
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}