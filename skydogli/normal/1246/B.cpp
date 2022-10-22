#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long
#define get hh
using namespace std;
#define LL long long
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
int a[100100],check[100100],tax[100005];
vector<int>num[100005];
LL sum;
int get[100010][110];
signed main(){
	n=read();k=read();
	for(register int i=1;i<=100000;i++){
		get[i][0]=1;
		for(register int j=1;j<=100;j++){
			if(get[i][j-1]*i>1e10)break;
			get[i][j]=get[i][j-1]*i;
		}
	}
	for(register int i=1;i<=n;i++){
		a[i]=read();
		for(register int j=2;j*j<=a[i];j++){
			if(!get[j][k])continue;
			while(a[i]%get[j][k]==0)a[i]/=get[j][k];
		}
		//cout<<a[i]<<' ';
	}
	int ans=0;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				//cout<<j<<" "<<a[i]<<endl;
				if(get[j][k] && get[j][k]%a[i]==0 && get[j][k]/a[i]<=100000){
					ans+=check[get[j][k]/a[i]];
				}
				if(j*j!=a[i] && get[a[i]/j][k] && get[a[i]/j][k]%a[i]==0 && get[a[i]/j][k]/a[i]<=100000){
					ans+=check[get[a[i]/j][k]/a[i]];
				}
			}
		}
		check[a[i]]++;
	}
	printf("%I64d",ans);
	/*
	for(register int i=1;i<=n;i++){
		for(register int d=1;d*d<=a[i];d++){
			if(a[i]%d==0){
				num[d].push_back(a[i]);
				if(a[i]/d!=d)
				num[a[i]/d].push_back(a[i]);
			}
		}
		tax[a[i]]++;
	}
	for(int i=1;i<=100000;++i){
		if(!num[i].size())continue;
		LL tmp=1;
		for(int j=1;j<=k;++j){
			tmp=tmp*i;
			if(tmp>100000)break;
		}
		cout<<"?? "<<tmp<<endl;
		if(tmp>100000)continue;
		for(int j=0;j<num[i].size();++j){
			if(tmp%num[i][j]==0){
				if(num[i][j]<tmp/num[i][j]){
					sum+=tax[tmp/num[i][j]];
					if(tax[tmp/num[i][j]])
					cout<<"add: "<<num[i][j]<<" tmp:"<<tmp<<endl;
				}
			}
		}
		int a=sqrt(tmp);
		if((double)a==sqrt(tmp)) sum+=tax[a]*(tax[a]-1)/2;
	}
	printf("%lld",sum);
	*/
	return 0;
}