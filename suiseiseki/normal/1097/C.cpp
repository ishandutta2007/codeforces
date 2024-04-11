#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define Maxn 100000
string s[Maxn+5];
int le[Maxn+5],ri[Maxn+5];
int l_n[5*Maxn+5],r_n[5*Maxn+5];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int ans=0;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<(int)s[i].size();j++){
			if(s[i][j]=='('){
				le[i]++;
			}
			else{
				if(le[i]>0){
					le[i]--;
				}
				else{
					ri[i]++;
				}
			}
		}
		if(le[i]!=0&&ri[i]!=0){
			continue;
		}
		if(le[i]==0&&ri[i]==0){
			num++;
		}
		if(le[i]==0){
			if(l_n[ri[i]]>0){
				ans++;
				l_n[ri[i]]--;
			}
			else{
				r_n[ri[i]]++;
			}
		}
		else{
			if(r_n[le[i]]>0){
				ans++;
				r_n[le[i]]--;
			}
			else{
				l_n[le[i]]++;
			}
		}
	}
	printf("%d\n",ans+(num>>1));
	return 0;
}