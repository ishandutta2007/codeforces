#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define Inf 0x7f7f7f7f
int cost[1005];
string s[1005];
map<string,int> MP;
int len;
void init(){
	MP["A"]=1;
	s[1]="A";
	MP["B"]=2;
	s[2]="B";
	MP["C"]=3;
	s[3]="C";
	MP["AA"]=4;
	s[4]="AA";
	MP["AB"]=5;
	s[5]="AB";
	MP["AC"]=6;
	s[6]="AC";
	MP["BA"]=7;
	s[7]="BA";
	MP["BB"]=8;
	s[8]="BB";
	MP["BC"]=9;
	s[9]="BC";
	MP["CA"]=10;
	s[10]="CA";
	MP["CB"]=11;
	s[11]="CB";
	MP["CC"]=12;
	s[12]="CC";
	len=12;
	string now;
	for(char i='A';i<='C';i++){
		for(char j='A';j<='C';j++){
			for(char k='A';k<='C';k++){
				now="";
				now+=i;
				now+=j;
				now+=k;
				MP[now]=++len;
				s[len]=now;
			}
		}
	}
}
int mn(int a,int b){
	return a<b?a:b;
}
bool check(string a,string b,string c){
	bool yes[3]={0};
	for(int i=0;i<(int)a.size();i++){
		yes[a[i]-'A']=1;
	}
	for(int i=0;i<(int)b.size();i++){
		yes[b[i]-'A']=1;
	}
	for(int i=0;i<(int)c.size();i++){
		yes[c[i]-'A']=1;
	}
	return yes[0]&&yes[1]&&yes[2];
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	string S;
	int c;
	memset(cost,0x1f,sizeof cost);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		cin>>S;
		cost[MP[S]]=mn(cost[MP[S]],c);
	}
	int ans=300005,now;
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				if(check(s[i],s[j],s[k])){
					now=cost[i]+cost[j]+cost[k];
					if(i==j&&j==k){
						now-=cost[i]*2;
					}
					else{
						if(i==j){
							now-=cost[i];
						}
						if(i==k){
							now-=cost[i];
						}
						if(j==k){
							now-=cost[j];
						}
					}
					ans=mn(ans,now);
				}
			}
		}
	}
	printf("%d\n",ans==300005?-1:ans);
	return 0;
}