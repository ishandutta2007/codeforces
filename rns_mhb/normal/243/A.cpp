#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v,vv;
#define M 2000005
bool f[M];
int a,n;
int main(){
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	v.clear();
	vv.clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		f[a]=1;
		vv.clear();
		vv.push_back(a);
		for(int j=0;j<v.size();j++){
			int k=v[j]|a;
			f[k]=1;
			if(k!=vv[vv.size()-1]) vv.push_back(k);
		}
		v.clear();
		for(int j=0;j<vv.size();j++) v.push_back(vv[j]);
	}
	int sum=0;
	for(int i=0;i<M;i++) sum+=f[i];
	printf("%d\n",sum);
	return 0;
}