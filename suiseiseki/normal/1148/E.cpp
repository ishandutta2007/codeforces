#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 300000
#define ll long long
struct Node{
	int a;
	int id;
	friend bool operator <(Node p,Node q){
		return p.a<q.a;
	}
}s[Maxn+5],t[Maxn+5];
int n;
int ans[Maxn*5+5][3];
int len;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].a);
		s[i].id=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i].a);
		t[i].id=i;
	}
	sort(s+1,s+1+n);
	sort(t+1,t+1+n);
	ll sum_1=0,sum_2=0;
	for(int i=1;i<=n;i++){
		sum_1+=s[i].a;
		sum_2+=t[i].a;
		if(sum_1>sum_2){
			puts("NO");
			return 0;
		}
	}
	if(sum_1!=sum_2){
		puts("NO");
		return 0;
	}
	int x,y;
	for(int i=1,j=1;i<=n;i++){
		if(s[i].a==t[i].a){
			continue;
		}
		while(s[i].a<t[i].a){
			while(s[j].a<=t[j].a){
				j++;
			}
			x=t[i].a-s[i].a;
			y=s[j].a-t[j].a;
			if(x<=y){
				ans[++len][0]=s[i].id;
				ans[len][1]=s[j].id;
				ans[len][2]=x;
				s[i].a+=x;
				s[j].a-=x;
			}
			else{
				ans[++len][0]=s[i].id;
				ans[len][1]=s[j].id;
				ans[len][2]=y;
				s[i].a+=y;
				s[j].a-=y;
			}
		}
	}
	puts("YES");
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}