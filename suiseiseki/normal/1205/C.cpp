#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[55][55];
int b[55][55];
int n;
int ans[10];
int main(){
	fflush(stdout);
	cin>>n;
	memset(a,-1,sizeof a);
	memset(b,-1,sizeof b);
	a[1][1]=1;
	a[n][n]=0;
	cout<<"? 1 1 2 2"<<endl;
	int x;
	cin>>x;
	a[2][2]=x;
	int c,d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=-1){
				continue;
			}
			if(((i+j)&1)){
				continue;
			}
			if(j-2<1){
				c=i-2;
				d=j;
			}
			else{
				c=i;
				d=j-2;
			}
			cout<<"? "<<c<<' '<<d<<' '<<i<<' '<<j<<endl;
			cin>>x;
			if(x==1){
				a[i][j]=a[c][d];
			}
			else{
				a[i][j]=a[c][d]^1;
			}
		}
	}
	b[1][2]=0;
	cout<<"? 1 2 2 3"<<endl;
	cin>>x;
	if(x==1){
		b[2][3]=0;
	}
	else{
		b[2][3]=1;
	}
	cout<<"? 2 1 2 3"<<endl;
	cin>>x;
	if(x==1){
		b[2][1]=b[2][3];
	}
	else{
		b[2][1]=b[2][3]^1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]!=-1){
				continue;
			}
			if(!((i+j)&1)){
				continue;
			}
			if(j-2<1){
				c=i-2;
				d=j;
			}
			else{
				c=i;
				d=j-2;
			}
			cout<<"? "<<c<<' '<<d<<' '<<i<<' '<<j<<endl;
			cin>>x;
			if(x==1){
				b[i][j]=b[c][d];
			}
			else{
				b[i][j]=b[c][d]^1;
			}
		}
	}
	int get_ans=-1;
	for(int i=1;i<=n&&get_ans==-1;i++){
		for(int j=1;j<=n-3&&get_ans==-1;j++){
			if(!((i+j)&1)){
				if((a[i][j]==a[i][j+2])==(b[i][j+1]==b[i][j+3])){
					cout<<"? "<<i<<' '<<j<<' '<<i<<' '<<j+3<<endl;
					cin>>x;
					if(x==1){
						if(a[i][j]==b[i][j+3]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(a[i][j]==b[i][j+3]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
					break;
				}
			}
			else{
				if((b[i][j]==b[i][j+2])==(a[i][j+1]==a[i][j+3])){
					cout<<"? "<<i<<' '<<j<<' '<<i<<' '<<j+3<<endl;
					cin>>x;
					if(x==1){
						if(b[i][j]==a[i][j+3]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(b[i][j]==a[i][j+3]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
				}
				break;
			}
		}
	}
	if(get_ans!=-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((!((i+j)&1))){
					continue;
				}
				a[i][j]=b[i][j]^get_ans;
			}
		}
		cout<<"!"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	for(int j=1;j<=n&&get_ans==-1;j++){
		for(int i=1;i<=n-3&&get_ans==-1;i++){
			if(!((i+j)&1)){
				if((a[i][j]==a[i+2][j])==(b[i+1][j]==b[i+3][j])){
					cout<<"? "<<i<<' '<<j<<' '<<i+3<<' '<<j<<endl;
					cin>>x;
					if(x==1){
						if(a[i][j]==b[i+3][j]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(a[i][j]==b[i+3][j]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
					break;
				}
			}
			else{
				if((b[i][j]==b[i+2][j])==(a[i+1][j]==a[i+3][j])){
					cout<<"? "<<i<<' '<<j<<' '<<i+3<<' '<<j<<endl;
					cin>>x;
					if(x==1){
						if(b[i][j]==a[i+3][j]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(b[i][j]==a[i+3][j]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
				}
				break;
			}
		}
	}
	if(get_ans!=-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!((i+j)&1)){
					continue;
				}
				a[i][j]=b[i][j]^get_ans;
			}
		}
		cout<<"!"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n-1&&get_ans==-1;i++){
		for(int j=1;j<=n-2&&get_ans==-1;j++){
			if(!((i+j)&1)){
				if((a[i][j]==a[i][j+2])==(b[i][j+1]==b[i+1][j+2])){
					cout<<"? "<<i<<' '<<j<<' '<<i+1<<' '<<j+2<<endl;
					cin>>x;
					if(x==1){
						if(a[i][j]==b[i+1][j+2]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(a[i][j]==b[i+1][j+2]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
					break;
				}
			}
			else{
				if((b[i][j]==b[i][j+2])==(a[i][j+1]==a[i+1][j+2])){
					cout<<"? "<<i<<' '<<j<<' '<<i+1<<' '<<j+2<<endl;
					cin>>x;
					if(x==1){
						if(b[i][j]==a[i+1][j+2]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(b[i][j]==a[i+1][j+2]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
					break;
				}
			}
		}
	}
	if(get_ans!=-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!((i+j)&1)){
					continue;
				}
				a[i][j]=b[i][j]^get_ans;
			}
		}
		cout<<"!"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n-2&&get_ans==-1;i++){
		for(int j=1;j<=n-1&&get_ans==-1;j++){
			if(!((i+j)&1)){
				if((a[i][j]==a[i+1][j+1])==(b[i][j+1]==b[i+2][j+1])){
					cout<<"? "<<i<<' '<<j<<' '<<i+2<<' '<<j+1<<endl;
					cin>>x;
					if(x==1){
						if(a[i][j]==b[i+2][j+1]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(a[i][j]==b[i+2][j+1]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
					break;
				}
			}
			else{
				if((b[i][j]==b[i+1][j+1])==(a[i][j+1]==a[i+2][j+1])){
					cout<<"? "<<i<<' '<<j<<' '<<i+2<<' '<<j+1<<endl;
					cin>>x;
					if(x==1){
						if(b[i][j]==a[i+2][j+1]){
							get_ans=0;
						}
						else{
							get_ans=1;
						}
					}
					else{
						if(b[i][j]==a[i+2][j+1]){
							get_ans=1;
						}
						else{
							get_ans=0;
						}
					}
					break;
				}
			}
		}
	}
	if(get_ans!=-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!((i+j)&1)){
					continue;
				}
				a[i][j]=b[i][j]^get_ans;
			}
		}
		cout<<"!"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	return 0;
}