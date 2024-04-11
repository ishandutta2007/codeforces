#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	bool a_is_bigger=1;
	fflush(stdout);
	cout<<'?'<<' '<<'0'<<' '<<'0'<<endl;
	int ret;
	scanf("%d",&ret);
	if(ret==-1){
		a_is_bigger=0;
	}
	int x,y;
	int a=0,b=0;
	for(int i=29;i>=0;i--){
		cout<<'?'<<' '<<(a^(1<<i))<<' '<<b<<endl;
		scanf("%d",&x);
		cout<<'?'<<' '<<a<<' '<<(b^(1<<i))<<endl;
		scanf("%d",&y);
		if(x==y){
			if(a_is_bigger){
				a^=(1<<i);
			}
			else{
				b^=(1<<i);
			}
			if(x==1){
				a_is_bigger=1;
			}
			else{
				a_is_bigger=0;
			}
		}
		else if(x==-1&&y==1){
			a^=(1<<i);
			b^=(1<<i);
		}
	}
	cout<<'!'<<' '<<a<<' '<<b<<endl;
	return 0;
}