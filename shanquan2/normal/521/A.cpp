#include<cstdio>
#define M 1000000007
using namespace std;

int cnt[4];
char s[100010];
int main(){
	int n;scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='A')cnt[0]++;
		if(s[i]=='T')cnt[1]++;
		if(s[i]=='G')cnt[2]++;
		if(s[i]=='C')cnt[3]++;
	}
	int max=0;
	for(int i=0;i<4;i++)if(cnt[i]>max)max=cnt[i];
	int s=0;for(int i=0;i<4;i++)if(cnt[i]==max)s++;
//	printf("%d %d\n",max,s);
	long long ans=1;
	for(int i=0;i<n;i++){
		ans*=s;
		ans%=M;
	}
	printf("%I64d\n",ans);
	return 0;
}