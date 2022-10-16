#include <map>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define Maxm 4000000
#define Maxn 200000
char s[Maxm+5];
map<string,int> mp;
struct Node{
	int id;
	int type;
	bool rev;
	bool chos;
}a[Maxn+5];
int num[5];
int ab(int a){
	return a<0?-a:a;
}
int main(){
	int t;
	int n;
	scanf("%d",&t);
	int len;
	int ans;
	string now;
	while(t--){
		num[0]=num[1]=num[2]=num[3]=0;
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			now="";
			scanf("%s",s+1);
			len=0;
			while(s[++len]!='\0');
			len--;
			for(int j=len;j>0;j--){
				now+=s[j];
			}
			a[i].id=i;
			a[i].type=(s[1]-'0')*2+(s[len]-'0');
			num[a[i].type]++;
			a[i].rev=1;
			a[i].chos=0;
			if(mp.count(now)>0){
				a[i].rev=0;
				a[mp[now]].rev=0;
				mp.erase(now);
			}
			else{
				now="";
				for(int j=1;j<=len;j++){
					now+=s[j];
				}
				mp[now]=i;
			}
		}
		if(num[1]+num[2]==0){
			if(num[0]==0||num[3]==0){
				puts("0");
				continue;
			}
			else{
				puts("-1");
				continue;
			}
		}
		ans=0;
		for(int i=1;i<=n&&ab(num[1]-num[2])>1;i++){
			if(a[i].type==1&&a[i].rev&&num[1]>num[2]){
				num[1]--;
				num[2]++;
				ans++;
				a[i].chos=1;
			}
			else if(a[i].type==2&&a[i].rev&&num[1]<num[2]){
				num[1]++;
				num[2]--;
				ans++;
				a[i].chos=1;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			if(a[i].chos){
				printf("%d ",a[i].id);
			}
		}
		puts("");
	}
	return 0;
}