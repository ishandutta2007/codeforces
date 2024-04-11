#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int a[Maxn+5];
int main(){
	int n;
	int num;
	ll ans;
	bool first;
		read(n);
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		num=0;
		ans=1;
		first=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				num++;
			}
			else{
				if(first){
					ans*=(num+1);
				}
				else{
					first=1;
				}
				num=0;
			}
		}
		if(!first){
			ans=0;
		}
		cout<<ans<<endl;
	return 0;
}