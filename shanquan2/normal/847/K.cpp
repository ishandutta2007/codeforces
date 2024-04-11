#include<bits/stdc++.h>
using namespace std;

int n,a,b,k,f,ans,q[100005],top;
map<pair<string,string>,int> A;
char s[25];
string u,v,lst;
int main(){
	scanf("%d%d%d%d%d%d",&n,&a,&b,&k,&f);
	for(int i=0;i<n;i++){
		scanf("%s",s);u=s;
		scanf("%s",s);v=s;
		int w=a;if(u==lst)w=b;
		lst=v;
		if(u>v)swap(u,v);
		A[make_pair(u,v)]+=w;ans+=w;
	}
	for(map<pair<string,string>,int>::iterator it=A.begin();it!=A.end();it++)
		q[top++]=-it->second+f;
	sort(q,q+top);
	for(int i=0;i<k&&i<top&&q[i]<0;i++)ans+=q[i];
	printf("%d\n",ans);
	return 0;
}