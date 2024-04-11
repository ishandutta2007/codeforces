    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    int read(){
    	int a=0,fh=1;char c=getchar();
    	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
    	while('0'<=c&&c<='9'){
    		a=a*10+c-48;
    		c=getchar();
    	}
    	return a*fh;
    }
    #define Ls (x<<1)
    #define Rs (x<<1|1)
    #define mid ((l+r)>>1)
    #define MN 1000005
    int n,m,p;
    int sum[MN<<2],a[MN];
    vector<int>v[MN<<2];
    void build(int x,int l,int r){
    	v[x].resize(r-l+2);
    	v[x][0]=-1e18;
    	for(int i=1;i<=r-l+1;++i)v[x][i]=1e18;
    	if(l==r){
    		sum[x]=a[l];
    		v[x][1]=p-a[l];
    		return;
    	}
    	build(Ls,l,mid);
    	build(Rs,mid+1,r);
    	sum[x]=sum[Ls]+sum[Rs];
    	int y=1;
    	for(int a=0;a<=mid-l+1;++a){
    		int vl=v[Ls][a]+sum[Ls]-a*p,vr=1e18;
    		if(a!=mid-l+1)vr=v[Ls][a+1]-1+sum[Ls]-a*p;
    		if(y)y--;
    		while(y!=v[Rs].size()&&vr>=v[Rs][y]){
    		//	if(l==3&&r==4)cerr<<vr<<" "<<v[Rs][y]<<"con: "<<a<<" "<<y<<": "<<vr+a*p-sum[Ls]-(vr-v[Rs][y])<<endl;
    			v[x][a+y]=min(v[x][a+y],max(vl-sum[Ls]+a*p,vr+a*p-sum[Ls]-(vr-v[Rs][y])));
				y++;
			}
		}
	//	cerr<<x<<" "<<l<<" "<<r<<": ";
	//	for(int i=0;i<v[x].size();++i)cerr<<v[x][i]<<" ";
	//	cerr<<endl;
    }
    vector<int>id;
    void FIND(int x,int l,int r,int b,int e){
    	if(b<=l&&r<=e){id.push_back(x);return;}
    	if(l>e||r<b)return;
    	if(b<=mid)FIND(Ls,l,mid,b,e);
    	if(e>mid)FIND(Rs,mid+1,r,b,e);
    }
    signed main(){
    	n=read();m=read();p=read();
    	for(int i=1;i<=n;++i){
    		a[i]=read();
    	}
    	build(1,1,n);
    	for(int i=1;i<=m;++i){
    		int l=read(),r=read();
    		id.clear();
    		FIND(1,1,n,l,r);
    		int lst=0;
    		for(int j=0;j<id.size();++j){
    			int x=id[j];
    			int pos=upper_bound(v[x].begin(),v[x].end(),lst)-v[x].begin()-1;
    			lst=lst+sum[x]-pos*p;
    		}
    		printf("%lld\n",lst);
    	}
    	return 0;
    }