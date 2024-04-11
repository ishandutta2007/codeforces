#include <stdio.h>
int a[100005];
bool del[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		for(int j=i-1;j>=1;j--)
			if(a[i]==a[j]) del[j]=true;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!del[i]) ans++;
	printf("%d\n", ans);
	for(int i=1;i<=n;i++)
		if(!del[i]) printf("%d ", a[i]);
	puts("");
	return 0;
}