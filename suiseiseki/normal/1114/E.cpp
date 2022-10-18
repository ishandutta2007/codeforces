#include <ctime>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000000
int a[70];
bool use[Maxn+5];
int main(){
	fflush(stdout);
	int n;
	scanf("%d",&n);
	int now=(1<<29);
	cout<<"> "<<now<<endl;
	int x;
	scanf("%d",&x);
	int num=59;
	while(x==0){
		now>>=1;
		cout<<"> "<<now<<endl;
		num--;
		scanf("%d",&x);
	}
	int left=now,right=(now<<1),mid;
	if(right>1000000000){
		right=1000000000;
	}
	while(left<right){
		mid=(left+right+1)>>1;
		cout<<"> "<<mid<<endl;
		num--;
		scanf("%d",&x);
		if(x==0){
			right=mid-1;
		}
		else{
			left=mid;
		}
	}
	int maxn=left+1;
	int len=0;
	srand(time(NULL));
	now=rand();
	while(num--){
		len++;
		if(len>n){
			len--;
			break;
		}
		now=rand()%n+1;
		while(use[now]){
			now++;
		}
		cout<<"? "<<now<<endl;
		use[now]=1;
		scanf("%d",&a[len]);
	}
	sort(a+1,a+1+len);
	int A,B;
	bool can;
	for(A=a[1];;A--){
		B=(maxn-A)/(n-1);
		if(B*(n-1)!=maxn-A){
			continue;
		}
		can=1;
		for(int i=1;i<=len;i++){
			if((a[i]-A)%B!=0){
				can=0;
				break;
			}
		}
		if(can){
			break;
		}
	}
	cout<<"! "<<A<<' '<<B<<endl;
	return 0;
}