#include<cstdio>
#include<algorithm>
using namespace std;

int a[100],b[100];
int main(){
	int n;scanf("%d",&n);
	int t=0;
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++){
		int c;scanf("%d",&c);
		for(int i=0;i<c;i++)
			scanf("%d",&a[i]);
		if(c&1)b[t++]=a[c>>1];
		for(int i=0;i<c/2;i++)
			ans1+=a[i],ans2+=a[c-i-1];
	}
	sort(b,b+t);
	for(int i=t-1;i>=0;i-=2){
		ans1+=b[i];
		if(i)ans2+=b[i-1];
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}