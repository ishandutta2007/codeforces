#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

string s,a,b,c;
int n;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> s;                              
	for (int i=0;i<s.size();i++)if (s[i]>='A'&&s[i]<='Z'||s[i]>='a'){
		if (s[i]<='Z')a+=s[i];else a+=s[i]-'a'+'A';
	}
	cin >> s;
	for (int i=0;i<s.size();i++)if (s[i]>='A'&&s[i]<='Z'||s[i]>='a'){
		if (s[i]<='Z')b+=s[i];else b+=s[i]-'a'+'A';
	}
	cin >> s;
	for (int i=0;i<s.size();i++)if (s[i]>='A'&&s[i]<='Z'||s[i]>='a'){
		if (s[i]<='Z')c+=s[i];else c+=s[i]-'a'+'A';
	}
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s;
		string t="";                                                   
		for (int i=0;i<s.size();i++)if (s[i]>='A'&&s[i]<='Z'||s[i]>='a'){
			if (s[i]<='Z')t+=s[i];else t+=s[i]-'a'+'A';
		}
		if (t==a+b+c||t==a+c+b||t==b+a+c||t==b+c+a||t==c+a+b||t==c+b+a)puts("ACC");else puts("WA");
		
	}
	return 0;
}