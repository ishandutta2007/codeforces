#include<bits/stdc++.h>
using namespace std;
#define MN 2005
int n,a[MN],b[MN],loc[MN];
vector<int>X,Y;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		loc[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		a[loc[b[i]]]=i;
	}
    //a:i
	//b:i
	for(int i=1;i<=n;++i){
		b[a[i]]=i;
	}
	int tot=0;
	for(int i=n;i;--i){
		int pos=0;
		for(int j=1;j<=n;++j)if(b[j]==i){pos=j;break;}
		for(int j=pos+1;j<=i;++j){
			if(b[j]<=pos) {
				tot+=(j-pos);
				swap(b[j],b[pos]);
				X.push_back(pos);
				Y.push_back(j);
				pos=j;
			}
		}
	}
	printf("%d\n%d\n",tot,(int)X.size());
	for(int i=0;i<X.size();++i)printf("%d %d\n",X[i],Y[i]);
	return 0;
}