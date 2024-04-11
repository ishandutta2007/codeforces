#include<bits/stdc++.h>
using namespace std;
#define mp  make_pair
#define pvv pair<vector<int>,vector<int> >
map<pvv,int>vis,deg;
bool work(vector<int>A,vector<int>B){
	bool ok=0;
	for(int i=0;i<B.size();++i)if(B[i])ok=1;
	if(!ok)return 0;
	if(vis.count(mp(A,B)))return vis[mp(A,B)];
	int ans=0;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(A[i]&&B[j]){
				A[i]--;B[j]--;
				A[(i+j)%5]++;
				ans|=work(B,A)^1;	
			}
		}
	return vis[mp(A,B)];
}
queue<pvv >Q;
int cnt;
void getdeg(vector<int>A){
	cerr<<"HI "<<cnt<<endl;
	for(int i=0;i<=8;++i)
		for(int j=0;j+i<=8;++j)
			for(int k=0;k+j+i<=8;++k)
				for(int l=0;l+k+j+i<=8;++l){
					int o=8-j-k-l-i;
					vector<int>B(5);
					B[0]=i;B[1]=j;B[2]=k;B[3]=l;B[4]=o;
					int tmp=0;
					for(int p=1;p<=4;++p)
						for(int q=1;q<=4;++q){
							if(A[p]&&B[q])tmp++;		
						}
					deg[mp(A,B)]=tmp;
				}
}
void pre(){
	for(int i=0;i<=8;++i)
		for(int j=0;j+i<=8;++j)
			for(int k=0;k+j+i<=8;++k)
				for(int l=0;l+k+j+i<=8;++l){
						int o=8-j-k-l-i;
						vector<int>A(5),B(5);
						A[0]=i;A[1]=j;A[2]=k;A[3]=l;A[4]=o;
						getdeg(A);
						B[0]=B[1]=B[2]=B[3]=B[4]=0;B[0]=8;
						vis[mp(A,B)]=-1;
						vis[mp(B,A)]=1;
						Q.push(mp(A,B));
						Q.push(mp(B,A));
						cnt++;
					}
//	cerr<<"cnt: "<<cnt<<endl;
	int out=0;
	while(!Q.empty()){
		out++;
//		if(out%1000==0)cerr<<"out: "<<out<<endl;
		pvv w=Q.front();Q.pop();
	//	cerr<<"out "<<vis[w]<<endl;
	//	for(int i=0;i<5;++i)cout<<w.first[i]<<" ";cout<<";";
	//	for(int i=0;i<5;++i)cout<<w.second[i]<<" ";cout<<";";
	//	puts("\n");
//		if(w.first[1]==2&&w.first[2]==2&&w.first[3]==2)exit(0);
		for(int z=0;z<=4;++z){
			for(int p=1;p<=4;++p){
				int q=(z+5-p)%5;
				if(!q||!w.first[q]||!w.second[z])continue;
				vector<int>A=w.first,B=w.second;
				B[z]--;B[p]++;
				swap(A,B);
				if(vis.count(mp(A,B)))continue;
				deg[mp(A,B)]--;
				if(vis[w]==-1){
					vis[mp(A,B)]=1;
					Q.push(mp(A,B));
				}
				else if(!deg[mp(A,B)]){
					vis[mp(A,B)]=-1;
					Q.push(mp(A,B));
				}
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	pre();
//	cerr<<"done"<<endl;
	while(T--){
		vector<int>A(5),B(5);
		int op;scanf("%d",&op);
		for(int i=0;i<5;++i)A[i]=B[i]=0;
		for(int i=1;i<=8;++i){
			int v;scanf("%d",&v);
			A[v]++;
		}
		for(int i=1;i<=8;++i){
			int v;scanf("%d",&v);
			B[v]++;
		}
		if(op)swap(A,B);
//		for(int i=0;i<5;++i)cout<<A[i]<<" ";cout<<";";
//		for(int i=0;i<5;++i)cout<<B[i]<<" ";cout<<";";
//		cerr<<"? "<<vis[mp(A,B)]<<endl;
		int tmp=vis[mp(A,B)];
		if(tmp==1)puts(op?"Bob":"Alice");
		else if(tmp==-1) puts(op?"Alice":"Bob");
		else puts("Deal");
	}
	return 0;
}