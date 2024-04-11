#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxn=30;
const int Maxd=65;
typedef long long ll;
ll a[Maxn+5];
int n,k;
int num[Maxd+5];
int main(){
	int T;
	cin>>T;
	bool flag;
	while(T--){
		cin>>n>>k;
		memset(num,0,sizeof num);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=0;a[i]>0;j++,a[i]/=k){
				num[j]+=a[i]%k;
			}
		}
		flag=1;
		for(int i=0;i<Maxd;i++){
			if(num[i]>1){
				flag=0;
				break;
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}