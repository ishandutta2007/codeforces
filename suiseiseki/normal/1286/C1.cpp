#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=100;
struct String{
	string s;
	friend bool operator <(String p,String q){
		if(p.s.size()==q.s.size()){
			return p.s<q.s;
		}
		return p.s.size()<q.s.size();
	}
}x;
multiset<String> st;
string s;
int n;
char now[Maxn+5];
int now_len;
char ans[Maxn+5];
int len;
int num[30];
int main(){
	fflush(stdout);
	cin>>n;
	if(n==1){
		cout<<"? 1 1"<<endl;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;i++){
		cin>>s;
		now_len=s.size();
		for(int j=0;j<now_len;j++){
			now[j]=s[j];
		}
		sort(now,now+now_len);
		for(int j=0;j<now_len;j++){
			s[j]=now[j];
		}
		x.s=s;
		st.insert(x);
	}
	cout<<"? 2 "<<n<<endl;
	multiset<String>::iterator it;
	for(int i=1;i<=n*(n-1)/2;i++){
		cin>>s;
		now_len=s.size();
		for(int j=0;j<now_len;j++){
			now[j]=s[j];
		}
		sort(now,now+now_len);
		for(int j=0;j<now_len;j++){
			s[j]=now[j];
		}
		x.s=s;
		it=st.find(x);
		st.erase(it);
	}
	it=st.begin();
	while(it!=st.end()){
		s=(*it).s;
		for(int i=0;i<(int)s.size();i++){
			num[s[i]-'a']++;
		}
		for(int i=1;i<=len;i++){
			num[ans[i]-'a']--;
		}
		len++;
		for(int i=0;i<26;i++){
			if(num[i]>0){
				ans[len]=(char)(i+'a');
				num[i]--;
			}
		}
		it++;
	}
	cout<<"! ";
	for(int i=1;i<=len;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}