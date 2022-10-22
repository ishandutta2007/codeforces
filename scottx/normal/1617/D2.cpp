#include<bits/stdc++.h>
using namespace std;
#define N 12345
typedef long long ll;
int n,a[N],c[N];
int Ask(int x,int y,int z){
	cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
	cin>>x;
	return x;	
}
void Solve(){
	cin>>n;
	int p0,p1;
	for(int i=1;i<=n;i+=3){
		a[i]=Ask(i,i+1,i+2);
		if(!a[i])p0=i;
		else p1=i;
	}
	static int jb[64];
	memset(jb,-1,sizeof(jb));
	jb[(1<<0)|(1<<1)|(1<<2)]=0;
	jb[(1<<3)|(1<<4)|(1<<5)]=1;
	
	jb[(1<<0)|(1<<1)|(1<<3)]=Ask(p0,p0+1,p1);
	jb[(1<<0)|(1<<1)|(1<<4)]=Ask(p0,p0+1,p1+1);
	jb[(1<<0)|(1<<2)|(1<<3)]=Ask(p0,p0+2,p1);
	jb[(1<<0)|(1<<2)|(1<<5)]=Ask(p0,p0+2,p1+2);
	jb[(1<<1)|(1<<2)|(1<<4)]=Ask(p0+1,p0+2,p1+1);
	
	jb[(1<<3)|(1<<4)|(1<<0)]=Ask(p1,p1+1,p0);
	jb[(1<<3)|(1<<4)|(1<<1)]=Ask(p1,p1+1,p0+1);
	jb[(1<<3)|(1<<5)|(1<<0)]=Ask(p1,p1+2,p0);
	jb[(1<<3)|(1<<5)|(1<<2)]=Ask(p1,p1+2,p0+2);
	jb[(1<<4)|(1<<5)|(1<<1)]=Ask(p1+1,p1+2,p0+1);
	int u0=-1,u1=-1;
	for(int i=1;i<=n;++i){
		c[i]=-1;
	}
	for(int i=0;i<64;++i){
		bool ok=true;
		for(int j=0;j<64;++j){
			if(~jb[j]){
				if((__builtin_popcount(i&j)>=2)!=jb[j]){
					ok=false;break;	
				}
			}
		}
		if(ok){
			for(int j=0;j<3;++j){
				c[p0+j]=i>>j&1;	
				c[p1+j]=i>>(j+3)&1;
				if(c[p0+j])u1=p0+j;
				else u0=p0+j;
				if(c[p1+j])u1=p1+j;
				else u0=p1+j;
			}
			break;
		}
	}
	for(int i=1;i<=n;i+=3){
		if(!~c[i]){
			c[i]=c[i+1]=c[i+2]=a[i];
			if(!a[i]){
				int t0=Ask(u1,i,i+1);
				int t1=Ask(u1,i+1,i+2);
				if(t0&t1)c[i+1]=1;
				else if(t0)c[i]=1;
				else if(t1)c[i+2]=1;
			}
			else{
				int t0=Ask(u0,i,i+1)^1;
				int t1=Ask(u0,i+1,i+2)^1;
				if(t0&t1)c[i+1]=0;
				else if(t0)c[i]=0;
				else if(t1)c[i+2]=0;	
			}
		}	
	}
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if(!c[i]){
			ans.push_back(i);
		}	
	}
	cout<<"! "<<ans.size();
	for(auto x:ans){
		cout<<' '<<x;
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}