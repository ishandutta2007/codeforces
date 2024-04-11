#include <cstdio>
#include <iostream>
using namespace std;
int x[5],y[5];
int ans_x[2],ans_y[2];
int main(){
	fflush(stdout);
	int n;
	cin>>n;
	int re;
	int cnt_x,cnt_y,cnt_ans;
	cnt_x=cnt_y=cnt_ans=0;
	for(int i=1;i<=n;i++){
		cout<<"? "<<i<<" 1 "<<i<<" "<<n<<endl;
		cin>>re;
		if(re&1){
			x[++cnt_x]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"? 1 "<<i<<" "<<n<<" "<<i<<endl;
		cin>>re;
		if(re&1){
			y[++cnt_y]=i;
		}
	}
	if(cnt_x==2&&cnt_y==2){
		cout<<"? "<<x[1]<<" "<<y[1]<<" "<<x[1]<<" "<<y[1]<<endl;
		cin>>re;
		if(re&1){
			cout<<"! "<<x[1]<<" "<<y[1]<<" "<<x[2]<<" "<<y[2]<<endl;
			return 0;
		}
		else{
			cout<<"! "<<x[1]<<" "<<y[2]<<" "<<x[2]<<" "<<y[1]<<endl;
			return 0;
		}
	}
	if(cnt_x==0){
		int left=1,right=n,mid;
		while(left<right){
			mid=(left+right)>>1;
			cout<<"? "<<1<<" "<<y[1]<<" "<<mid<<" "<<y[1]<<endl;
			cin>>re;
			if(re&1){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		cout<<"! "<<left<<" "<<y[1]<<" "<<left<<" "<<y[2]<<endl;
	}
	else{
		int left=1,right=n,mid;
		while(left<right){
			mid=(left+right)>>1;
			cout<<"? "<<x[1]<<" "<<1<<" "<<x[1]<<" "<<mid<<endl;
			cin>>re;
			if(re&1){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		cout<<"! "<<x[1]<<" "<<left<<" "<<x[2]<<" "<<left<<endl;
	}
	return 0;
}