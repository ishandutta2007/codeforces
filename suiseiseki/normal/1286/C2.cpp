#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=100;
int n;
string s;
string ans;
multiset<string> st[Maxn+5];
vector<string> a[Maxn+5];
int f[Maxn+5][26];
int num[26];
int main(){
	cin>>n;
	if(n==1){
		cout<<"? 1 1"<<endl;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	int m=((n+1)>>1);
	if(m==1){
		cout<<"? 1 1"<<endl;
		cin>>s;
		ans=s;
	}
	else{
		cout<<"? 1 "<<m<<endl;
		for(int i=1;i<=m*(m+1)/2;i++){
			cin>>s;
			sort(s.begin(),s.end());
			st[s.size()].insert(s);
		}
		cout<<"? 2 "<<m<<endl;
		for(int i=1;i<=m*(m-1)/2;i++){
			cin>>s;
			sort(s.begin(),s.end());
			st[s.size()].erase(st[s.size()].find(s));
		}
		for(int i=1;i<=m;i++){
			s=*(st[i].begin());
			for(int j=0;j<(int)s.size();j++){
				num[s[j]-'a']++;
			}
			for(int j=0;j<(int)ans.size();j++){
				num[ans[j]-'a']--;
			}
			for(int j=0;j<26;j++){
				if(num[j]>0){
					ans+=(char)(j+'a');
					num[j]=0;
				}
			}
		}
	}
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;i++){
		cin>>s;
		sort(s.begin(),s.end());
		a[s.size()].push_back(s);
		for(int j=0;j<(int)s.size();j++){
			f[s.size()][s[j]-'a']++;
		}
	}
	for(int i=n-m;i>0;i--){
		for(int j=0;j<26;j++){
			num[j]=f[i][j]-f[i-1][j];
		}
		for(int j=i-1;j<(int)ans.size();j++){
			num[ans[j]-'a']--;
		}
		for(int j=0;j<26;j++){
			if(num[j]>0){
				ans+=(char)(j+'a');
				num[j]=0;
			}
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;
}