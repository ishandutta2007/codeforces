#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[200005];
int qzh[200005],hzh[200005];
set<int> stab;

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]==s[i%n+1]){
			stab.insert(i);
			stab.insert(i%n+1);
		}
	}
	if(!stab.size()){
		for(int i=1;i<=n;i++){
			if(m%2){
				printf("%c",'B'^'W'^s[i]);
			}else{
				printf("%c",s[i]);
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		set<int>::iterator ff=stab.lower_bound(i);
		set<int>::iterator ss=ff;
		if(ss==stab.begin()){
			ss=stab.end();
		}
		ss--;
		if(ff==stab.end()){
			ff=stab.begin();
		}
		int disf,diss;
		if(*ff>i){
			disf=min(*ff-i,i+n-*ff);
		}else{
			disf=min(i-*ff,*ff+n-i);
		}
		if(*ss>i){
			diss=min(*ss-i,i+n-*ss);
		}else{
			diss=min(i-*ss,*ss+n-i);
		}
		if(min(disf,diss)>m){
			if(m%2){
				printf("%c",'B'^'W'^s[i]);
			}else{
				printf("%c",s[i]);
			}
			continue;
		}
		if(disf<diss){
			printf("%c",s[*ff]);
		}else{
			printf("%c",s[*ss]);
		}
	}
	return 0;
}