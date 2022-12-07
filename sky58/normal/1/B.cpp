#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
bool ch(string a){
	int n=a.size(),i,t=0;
	for(i=0;i<n;i++){
		if(a[i]<='Z' && a[i]>='A') t++;
	}
	for(i=0;i<n;i++){
		if(a[i]>'Z' || a[i]<'A'){
			if(i==t-1) return true;return false;
		}
	}
}
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string dec(int a){
	string ret="";
	while(a>0){
		a-=1;ret+=(a%26+'A');a/=26;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int main()
{
	int n,i;vector <string> out;
	cin>>n;
	for(i=0;i<n;i++){
		string s,o="";cin>>s;int r=0,c=0,it=0;s+='E';
		if(ch(s)){
//			cout<<"a\n";
			o+="R";
			while(s[it]<='Z' && s[it]>='A'){
				c*=26;c+=(s[it]-'A')+1;it++;
			}
			while(s[it]!='E'){
				r*=10;r+=(s[it]-'0');it++;
			}
			o+=moji(r);o+='C';o+=moji(c);
		}
		else{
//			cout<<"b\n";
			it++;
			while(s[it]!='C'){
				r*=10;r+=(s[it]-'0');it++;
			}
			it++;
			while(s[it]!='E'){
				c*=10;c+=(s[it]-'0');it++;
			}
			o+=dec(c);o+=moji(r);
		}
		out.pb(o);
	}
	for(i=0;i<n;i++) cout<<out[i]<<endl;
	return 0;
}