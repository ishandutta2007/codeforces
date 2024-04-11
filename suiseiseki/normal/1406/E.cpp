#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=100000;
int n;
bool np[Maxn+5];
int p[Maxn+5],p_len;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=n;i++){
		if(!np[i]){
			p[++p_len]=i;
			if(1ll*i*i>n){
				continue;
			}
			for(int j=i*i;j<=n;j+=i){
				np[j]=1;
			}
		}
	}
}
int main(){
	fflush(stdout);
	cin>>n;
	init();
	int ans=1,len=0;
	for(int i=1;i<=p_len&&1ll*p[i]*p[i]<=n;i++){
		len=i;
		if(p[i]>n){
			break;
		}
		if(1ll*ans*p[i]>n){
			break;
		}
		cout<<"B "<<p[i]<<endl;
		int f__k;
		cin>>f__k;
		int tmp=1;
		for(int j=1,sum=p[i];sum<=n;sum*=p[i],j++){
			if(sum>n){
				break;
			}
			cout<<"A "<<sum<<endl;
			int x;
			cin>>x;
			if(x==0){
				break;
			}
			tmp=sum;
			if(1ll*sum*p[i]>n){
				break;
			}
		}
		ans*=tmp;
	}
	len++;
	int block=300;
	int num;
	cout<<"A "<<1<<endl;
	cin>>num;
	for(int i=len;i<=p_len;i+=block){
		for(int j=i;j<=p_len&&j<i+block;j++){
			if(1ll*ans*p[j]>n){
				break;
			}
			cout<<"B "<<p[j]<<endl;
			int f__k;
			cin>>f__k;
			num-=f__k;
		}
		cout<<"A "<<1<<endl;
		int x;
		cin>>x;
		if(x!=num){
			for(int j=i;j<=p_len&&j<i+block;j++){
				cout<<"A "<<p[j]<<endl;
				int tmp;
				cin>>tmp;
				if(tmp==1){
					ans*=p[j];
					break;
				}
			}
			break;
		}
	}
	cout<<"C "<<ans<<endl;
	return 0;
}