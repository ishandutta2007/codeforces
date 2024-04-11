#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[300],fa[300];
char ch[500];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
vector<int> id[300],nm[300];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),fa[i]=i;
	for(int i=0;i<n;i++){
		scanf("%s",ch);
		for(int j=0;j<n;j++)
			if(ch[j]=='1'){
				int p=find(i),q=find(j);
				if(p!=q)fa[q]=p;
			}
	}
	for(int i=0;i<n;i++){
		int p=find(i);
		id[p].push_back(i);
		nm[p].push_back(a[i]);
	}
	for(int i=0;i<n;i++)if(nm[i].size()!=0)
		sort(nm[i].begin(),nm[i].end());
	for(int i=0;i<n;i++)if(nm[i].size()!=0){
		for(int j=0;j<nm[i].size();j++)
			a[id[i][j]]=nm[i][j];
	}
	printf("%d",a[0]);for(int i=1;i<n;i++)printf(" %d",a[i]);printf("\n");
	return 0;
}