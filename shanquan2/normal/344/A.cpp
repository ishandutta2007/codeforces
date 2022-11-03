#include<cstdio>
using namespace std;

int main(){
	int ans=1;
	int n;
	bool last=0;
	scanf("%d",&n);
	char c[3];
	scanf("%s",c);
	last=(c[1]=='1');
	for(int i=1;i<n;i++){
		scanf("%s",c);
		if(last && c[0]=='1' || !last && c[0]=='0')ans++;
		last=(c[1]=='1');
	}
	printf("%d\n",ans);
	return 0;
}