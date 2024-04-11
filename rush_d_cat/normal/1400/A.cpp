#include <bits/stdc++.h>
using namespace std;
int t,n;
char s[10002];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d%s",&n,s);
		while(1){
			vector<string> v;
			for(int i=0;i<n;i++){
				string str="";
				for(int j=i;j<i+n;j++){
					str+=s[j];
				}	
				v.push_back(str);
			}
			string res = "";
			for(int i=0;i<n;i++){
				res+=rand()%2+'0';
			}
			bool ok = 1;
			for(auto str: v) {
				bool tmp=0;
				for(int i=0;i<n;i++)
					if(str[i]==res[i]) tmp=1;
				ok &= tmp;
			}
			if(ok) {
				cout << res << endl; break;
			}
		}
	}
}